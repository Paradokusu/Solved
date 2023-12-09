#include <bits/stdc++.h>

using i64 = long long;

struct node {
	i64 id, sum, pt;
	
	friend bool operator < (const node &a, const node &b) {
		if (a.sum == b.sum) {
			if (a.pt == b.pt)
				return a.id < b.id;
			return a.pt < b.pt;
		}
		return a.sum > b.sum;
	}
};

void solve() {
	i64 n, m, h;
	std::cin >> n >> m >> h;
	std::vector<node> a(n + 5);
	std::vector<i64> t(m + 5), sum(m + 5);
	for (i64 i = 1; i <= n; i++) {
		i64 res = 0, k;
		for (i64 j = 1; j <= m; j++)
			std::cin >> t[j];
		std::sort(t.begin() + 1, t.begin() + m + 1);
		for (i64 j = 1; j <= m; j++)
			sum[j] = sum[j - 1] + t[j];
		for (k = 1; k <= m; k++) {
			if (sum[k] > h) break;
			res = res + sum[k];
		}
		a[i].sum = k, a[i].pt = res, a[i].id = i;
	}
	std::sort(a.begin() + 1, a.begin() + n + 1);
	for (i64 i = 1; i <= n; i++) {
		if (a[i].id == 1) {
			std::cout << i << "\n";
			return;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
