#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 5;

int n, m, cnt;

struct juice {
	i64 d, p, l;
	
	friend bool operator < (const juice& a, const juice& b) {
		return a.d < b.d;
	}
} x[N];

struct node {
	int l, r;
	i64 lit, w;	// 区间总体积和购买这些体积的价格
} t[N * 128];

int rt[N];

void Update(int& o, int l, int r, i64 p, i64 lit) {
	t[++cnt] = t[o], o = cnt, t[o].lit += lit, t[o].w += p * lit;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (mid >= p) Update(t[o].l, l, mid, p, lit);
	else Update(t[o].r, mid + 1, r, p, lit);
}

i64 Query(int o, int lsto, int l, int r, i64 lit) {
	if (l == r) return 1ll * lit * r;
	int mid = (l + r) / 2;
	i64 tot = t[t[lsto].l].lit - t[t[o].l].lit;
	if (tot >= lit) return Query(t[o].l, t[lsto].l, l, mid, lit);
	return t[t[lsto].l].w - t[t[o].l].w + Query(t[o].r, t[lsto].r, mid + 1, r, lit - tot);
}

int main() {
	scanf("%d %d", &n, &m);
	i64 maxP = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &x[i].d, &x[i].p, &x[i].l);
		maxP = std::max(maxP, x[i].p);
	}
	std::sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) {
		rt[i] = rt[i - 1];
		Update(rt[i], 1, maxP, x[i].p, x[i].l);
	}

	while (m--) {
		i64 G, L;
		scanf("%lld %lld", &G, &L);
		i64 l = 1, r = n, ans = -1;
		while (l <= r) {
			i64 mid = (l + r) / 2;
			if (Query(rt[mid - 1], rt[n], 1, maxP, L) <= G && t[rt[n]].lit - t[rt[mid - 1]].lit >= L) {
				l = mid + 1, ans = mid;
			} else {
				r = mid - 1;
			}
		}
		if (ans == -1) printf("-1\n");
		else printf("%lld\n", x[ans].d);
	}
	return 0;
}
