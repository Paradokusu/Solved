#include <bits/stdc++.h>

constexpr int N = 1007;

int n, dp[N][N];
char s[N];

int main() {
	scanf(" %s", s);
	n = strlen(s);
	
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == s[i - 1])
			dp[i - 1][i] = 0;
		else
			dp[i - 1][i] = 1;
	}
	
	for (int L = 2; L < n; L++) {
		for (int i = 0; i + L < n; i++) {
			int j = i + L;
			dp[i][j] = std::min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
			if (s[i] == s[j])
				dp[i][j] = std::min(dp[i + 1][j - 1], dp[i][j]);
		}
	}
	
	printf("%d\n", dp[0][n - 1]);
	return 0;
}

