#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using i64 = long long;
constexpr int N = 2e5 + 5;

int n, m, tot, pre = 1;
int b[N], rt[N];

struct _Q {
	int l, r, c, s;
} t[N * 128];

pair<int, int> a[N];

int Build(int l, int r) {
	int o = ++tot;
	if (l == r) return o;
	int mid = (l + r) >> 1;
	t[o].l = Build(l, mid), t[o].r = Build(mid + 1, r);
	return o; 
}

int Mdf(int o, int l, int r, int p, int k) {
	int u = ++tot;
	t[u] = t[o];
	if (l == r) { t[u].c += k, t[u].s += k * b[p]; return u; }
	int mid = (l + r) >> 1;
	if (p <= mid) t[u].l = Mdf(t[o].l, l, mid, p, k);
	else t[u].r = Mdf(t[o].r, mid + 1, r, p, k);
	t[u].c = t[t[u].l].c + t[t[u].r].c, t[u].s = t[t[u].l].s + t[t[u].r].s;
	return u;
}

int Qur(int p, int l, int r, int k) {
	if (l == r) return t[p].s / t[p].c * k;
	int mid = (l + r) >> 1;
	if (k <= t[t[p].l].c) return Qur(t[p].l, l, mid, k);
	else return t[t[p].l].s + Qur(t[p].r, mid + 1, r, k - t[t[p].l].c);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int p = (i << 1) - 1, q = i << 1;
		scanf("%d %d %d", &a[p].x, &a[q].x, &a[p].y);
		++a[q].x, a[q].y = -a[p].y, b[i] = a[p].y;
	}
	sort(b + 1, b + n + 1);
	int w = unique(b + 1, b + n + 1) - b - 1;
	rt[0] = Build(1, w);
	sort(a + 1, a + (n << 1) + 1);
	int k = 1;
	for (int i = 1; i <= (n << 1); i++) {
		while (k < a[i].x) { rt[k + 1] = rt[k]; k++; }
		if (k == n + 1) break;
		int p = lower_bound(b + 1, b + w + 1, abs(a[i].y)) - b;
		rt[k] = Mdf(rt[k], 1, w, p, (a[i].y > 0 ? 1 : -1));
	}
	while (m--) {
		int xi, ai, bi, ci;
		scanf("%d %d %d %d", &xi, &ai, &bi, &ci);
		const int mod = ci;
		int ki = (1ll * ai * pre + bi) % mod + 1;
		if (t[rt[xi]].c <= ki) printf("%d\n", pre = t[rt[xi]].s);
		else printf("%d\n", pre = Qur(rt[xi], 1, w, ki));
	}
	return 0;
}
