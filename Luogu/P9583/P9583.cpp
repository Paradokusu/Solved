#include <bits/stdc++.h>

typedef long long i64;

void solve() {
	i64 n, m, q, k;
	std::cin >> n >> m >> q >> k;
	std::vector<i64> row(n + 5), col(m + 5);
	std::map<i64, i64> a;
	i64 ans = n * m;

	while (q--) {
		i64 op, x;
		std::cin >> op >> x;

		if (op == 1) 
			row[x]++, row[x] %= k;
		else if (op == 2)
			col[x]++, col[x] %= k;
	}

	for (i64 i = 1; i <= m; i++)
		a[col[i]]++;

	for (i64 i = 1; i <= n; i++)
		ans -= (a[-row[i]] + a[k - row[i]]);
	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
