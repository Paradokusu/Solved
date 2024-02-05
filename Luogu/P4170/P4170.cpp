#include <bits/stdc++.h>

using namespace std;

constexpr int N = 57;

int n, dp[N][N];
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(dp, 0x3f, sizeof(dp));
	
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;
	
	for (int l = 1; l < n; l++) {
		for (int i = 1, j = 1 + l; j <= n; i++, j++) {
			if (s[i] == s[j])
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			else
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	
	printf("%d\n", dp[1][n]);
	return 0;
}
