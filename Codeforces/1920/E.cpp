#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
	int n, k;
	std::cin >> n >> k;
	k++;
	std::vector<std::vector<i64>> f(n + 1, std::vector<i64>(n + 1, -1));
	i64 ans = 0;

	for (int i = 1; i <= n; i++)
		f[0][i] = 1;

	std::function<i64(int, int)> calc = [&](int x, int y) {
		if (~f[x][y]) return f[x][y];
		
		f[x][y] = 0;
		for (int i = 1; i <= k - y && i * y <= x; i++)
			(f[x][y] += calc(x - i * y, i)) %= MOD;

		return f[x][y];
	};

	for (int i = 1; i <= n && i < k; i++)
		(ans += calc(n, i)) %= MOD;

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
