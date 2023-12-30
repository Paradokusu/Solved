#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 3e6 + 7;
constexpr int mod = 19260817;

mt19937 rnd(time(nullptr));

int n, q, cnt;
int a[N], pre[N], lsh[N << 2], val[N << 2];
i64 tr[N];
bitset<N> ans;

struct ask {
	int op, x, pos, l, r, k;
} t[N];

int lowbit(int x) {
	return x & -x;
}

void init(int n) {
	for (int i = 1; i <= n; i++)
		tr[i] = 0;
}

void add(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += y;
}

i64 sum(int x) {
	i64 res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += tr[i];
	return res;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		lsh[++cnt] = a[i];
	}

	for (int i = 1; i <= q; i++) {
		scanf("%d", &t[i].op);
		if (t[i].op == 1) {
			scanf("%d", &t[i].pos);
			scanf("%d", &t[i].x);
			lsh[++cnt] = t[i].x;
		} else {
			scanf("%d %d %d", &t[i].l, &t[i].r, &t[i].k);
			ans[i] = ((t[i].r - t[i].l + 1) % t[i].k == 0);
		}
	}

	sort(lsh + 1, lsh + cnt + 1);
	cnt = unique(lsh + 1, lsh + cnt + 1) - lsh - 1;

	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(lsh + 1, lsh + cnt + 1, a[i]) - lsh;

	for (int i = 1; i <= q; i++)
		if (t[i].op == 1)
			t[i].x = lower_bound(lsh + 1, lsh + cnt + 1, t[i].x) - lsh;

	while (1.0 * clock() / CLOCKS_PER_SEC < 2.8) {
		init(n);
		for (int i = 1; i <= cnt; i++)
			val[i] = rnd() % mod;
		for (int i = 1; i <= n; i++) {
			pre[i] = a[i];
			add(i, val[a[i]]);
		}
		for (int i = 1; i <= q; i++) {
			if (t[i].op == 1) {
				add(t[i].pos, val[t[i].x] - val[pre[t[i].pos]]);
				pre[t[i].pos] = t[i].x;
			} else {
				ans[i] = ans[i] & ((sum(t[i].r) - sum(t[i].l - 1)) % t[i].k == 0);
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		if (t[i].op == 2) {
			if (ans[i]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
