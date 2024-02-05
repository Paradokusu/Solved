#include <bits/stdc++.h>

using namespace std;

constexpr int N = 50 + 7;

int n, c;
int pos[N], w[N], sum[N];
int dp[N][N][2];

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &pos[i], &w[i]);
		sum[i] = sum[i - 1] + w[i];
	}
	
	memset(dp, 0x3f, sizeof(dp));
	
	dp[c][c][0] = dp[c][c][1] = 0;
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			dp[i][j][1] = min(dp[i + 1][j][1] + (pos[i + 1] - pos[i]) * (sum[n] - sum[j] + sum[i]), dp[i + 1][j][0] + (pos[j] - pos[i]) * (sum[n] - sum[j] + sum[i]));
			dp[i][j][0] = min(dp[i][j - 1][0] + (pos[j] - pos[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]), dp[i][j - 1][1] + (pos[j] - pos[i]) * (sum[i - 1] + sum[n] - sum[j - 1]));
		}
	}
	
	printf("%d\n", min(dp[1][n][1], dp[1][n][0]));
	return 0;
}
