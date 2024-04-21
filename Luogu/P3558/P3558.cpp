#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;

int n;
int a[N], dp[N][5];	// dp：下标为 i，其值为 j 的情况下的最小操作次数，下 reach 数组相同，坐标加 2 避免考虑负数情况
bool rcb[N][5];	// 能否到达

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	memset(dp, 0x3f, sizeof(dp));
	
	dp[1][a[1] + 2] = 0;
	rcb[1][a[1] + 2] = 1;
	
	for (int i = 2; i <= n; i++) {
		if (a[i] == -1) {
			if (rcb[i - 1][1]) {
				dp[i][1] = dp[i - 1][1];
				rcb[i][1] = 1;
			}
			
			if (rcb[i - 1][3]) {
				dp[i][3] = dp[i - 1][3] + 2;
				rcb[i][3] = 1;
			}
		}
		
		if (a[i] == 0) {
			if (rcb[i - 1][1]) {
				dp[i][1] = dp[i - 1][1] + 1;
				rcb[i][1] = 1;
				
				dp[i][2] = dp[i - 1][1];
				rcb[i][2] = 1;
			}
			
			if (rcb[i - 1][2]) {
				dp[i][2] = std::min(dp[i][2], dp[i - 1][2]);
				rcb[i][2] = 1;
			}
			
			if (rcb[i - 1][3]) {
				dp[i][3] = dp[i - 1][3] + 1;
				rcb[i][3] = 1;
			}
		}
		
		if (a[i] == 1) {
			if (rcb[i - 1][1]) {
				dp[i][1] = dp[i - 1][1] + 2;
				rcb[i][1] = 1;
				
				dp[i][2] = dp[i - 1][1] + 1;
				rcb[i][2] = 1;
				
				dp[i][3] = dp[i - 1][1];
				rcb[i][3] = 1;
			}
			
			if (rcb[i - 1][2]) {
				dp[i][3] = std::min(dp[i][3], dp[i - 1][2]);
				rcb[i][3] = 1;
			}
			
			if (rcb[i - 1][3]) {
				dp[i][3] = std::min(dp[i][3], dp[i - 1][3]);
				rcb[i][3] = 1;
			}
		}
	}
	
	if (!rcb[n][1] && !rcb[n][2] && !rcb[n][3])
		std::cout << "BRAK\n";
	else
		std::cout << std::min({dp[n][1], dp[n][2], dp[n][3]}) << "\n";
	
	return 0;
}
