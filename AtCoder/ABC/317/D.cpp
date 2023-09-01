#include <bits/stdc++.h>

typedef long long i64;

void solve() {
	constexpr i64 INF = 1e18;

	int n;
	std::cin >> n;
	std::vector<int> X(n + 5), Y(n + 5), Z(n + 5);
	for (int i = 0; i < n; i++)
		std::cin >> X[i] >> Y[i] >> Z[i];
	int z_sum = std::accumulate(Z.begin(), Z.end(), 0);

	std::vector<i64> dp(z_sum + 5, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int x = X[i], y = Y[i], z = Z[i];
		int w = std::max(0, (x + y) / 2 + 1 - x);
		for (int j = z_sum; j >= z; j--)
			dp[j] = std::min(dp[j], dp[j - z] + w);
	}

	i64 ans = INF;
	for (int i = z_sum / 2 + 1; i <= z_sum; i++)
		ans = std::min(ans, dp[i]);

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
