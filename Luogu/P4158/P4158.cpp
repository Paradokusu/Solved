#include <bits/stdc++.h>

constexpr int N = 55;

int n, m, t;
int ans;
int s[N][N];
int dp[N][N][N * N][2];	// dp[i][j][k][0 / 1]: 走到 i，刷了 j 次，刷了 k 次，有没有刷对

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> t;
	
	for (int i = 1; i <= n; i++) {
		std::string c;
		std::cin >> c;
		c = '#' + c;
		
		for (int j = 1; j <= m; j++)
			s[i][j] = c[j] - '0';
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= t; k++) {
				if (j == 1) {
					dp[i][j][k][0] = std::max(dp[i - 1][m][k - 1][0], dp[i - 1][m][k - 1][1]);
					dp[i][j][k][1] = std::max(dp[i - 1][m][k - 1][1], dp[i - 1][m][k - 1][0]) + 1;
				} else {
					if (s[i][j] == s[i][j - 1]) {
						dp[i][j][k][1] = dp[i][j - 1][k][1] + 1;
						dp[i][j][k][0] = dp[i][j - 1][k][0];
					} else {
						dp[i][j][k][1] = std::max(dp[i][j - 1][k - 1][1] + 1, dp[i][j - 1][k][0] + 1);
						dp[i][j][k][0] = std::max(dp[i][j - 1][k][1], dp[i][j - 1][k - 1][0]);
					}
				}
				
				ans = std::max({dp[i][j][k][0], dp[i][j][k][1], ans});
			}
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}
