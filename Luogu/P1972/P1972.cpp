#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e6 + 5;

struct node {
	int l, r, id;
	
	friend bool operator < (const node &x, const node &y) {
		return x.r < y.r;
	}
} q[N];

int n, m, a[N];
i64 bit[N], vis[N], ans[N];

i64 lowbit(i64 x) {
	return x & -x;
}

void add(i64 x, i64 y) {
	for (i64 i = x; i <= n; i += lowbit(i))
		bit[i] += y;
}

i64 sum(i64 x) {
	i64 res = 0;
	for (i64 i = x; i; i -= lowbit(i))
		res += bit[i];
	return res;
}

int main() {
	scanf("%d", &n);
	for (i64 i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + m + 1);

	i64 last = 1;
	for(int i = 1; i <= m; i++) {
		for (int j = last; j <= q[i].r; j++) {
			if (vis[a[j]]) add(vis[a[j]], -1);
			add(j, 1);
			vis[a[j]] = j;
		}
		last = q[i].r + 1;
		ans[q[i].id] = sum(q[i].r) - sum(q[i].l - 1);
	}
	
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}
