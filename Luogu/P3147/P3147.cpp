#include <bits/stdc++.h>

using namespace std;

constexpr int M = 262144;
constexpr int C = __lg(M) + 40;
constexpr int N = C + 7;

int n, ans;
int dp[N][M + 7];	// dp[i][j] 为以 j 为左端点合并出 i - 1 时的右端点位置

int main() {
	scanf("%d", &n);
	for (int i = 1, in; i <= n; i++) {
		scanf("%d", &in);
		dp[in][i] = i + 1;
	}
	
	for (int i = 2; i <= C; i++) {
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j])
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
			if (dp[i][j])
				ans = i;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
