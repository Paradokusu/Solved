#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3007;

int n, k, p, len = 1;
int dp[N][N][2];
i64 ans;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			std::cin >> dp[i][j][0];
	}
	
	while ((len << 1) < k) {
		len <<= 1;
		
		for (int i = 1; i + len - 1 <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j][p ^ 1] = std::max({
					dp[i][j][p],
					dp[i + (len >> 1)][j][p],
					dp[i + (len >> 1)][j + (len >> 1)][p],
					dp[i + (len >> 2)][j][p],
					dp[i + (len >> 2)][j + (len >> 2)][p],
					dp[i + (len >> 1)][j + (len >> 2)][p]
				});
			}
		}
		
		p ^= 1;
	}
	
	for (int i = 1; i + k - 1 <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans += std::max({
				dp[i][j][p],
				dp[i + k - len][j][p],
				dp[i + k - len][j + k - len][p],
				dp[i + ((k - len) >> 1)][j][p],
				dp[i + ((k - len) >> 1)][j + ((k - len) >> 1)][p],
				dp[i + k - len][j + ((k - len) >> 1)][p],
			});
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}
