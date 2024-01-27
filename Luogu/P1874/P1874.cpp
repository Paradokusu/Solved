#include <bits/stdc++.h>

constexpr int N = 50;
constexpr int S = 1e5 + 7;
constexpr int inf = 1e9;

int n, t;
int dp[N][S], num[N][N];
char str[N];

int main() {
	scanf("%s %d", str, &t);
	n = strlen(str);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = -1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (num[j][i - 1] > t) num[j][i] = inf;
			else num[j][i] = num[j][i - 1] * 10 + str[i - 1] - 48;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int s = 0; s <= t; s++)
			for (int j = i - 1; j >= 0 && num[j + 1][i] <= t; j--)
				if (s >= num[j + 1][i]) 
					dp[i][s] = std::min(dp[i][s], dp[j][s - num[j + 1][i]] + 1);
	}
	
	printf("%d\n", dp[n][t] < S ? dp[n][t] : -1);
	return 0;
}

