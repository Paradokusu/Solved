#include <bits/stdc++.h>

using namespace std;

constexpr int N = 207;
constexpr int inf = 2147483647;

int n, ans = -inf;
int a[N], g[N][N], dp[N][N];
char c[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %c %d", &c[i], &a[i]);
		a[n + i] = a[i];
		c[n + i] = c[i];
	}
	
	memset(dp, -0x3f, sizeof(dp));
	memset(g, 0x3f, sizeof(g));
	
	for (int i = 1; i <= (n << 1); i++)
		dp[i][i] = g[i][i] = a[i];
	
	for (int L = 2; L <= n; L++) {
		for (int i = 1, j = L; j <= (n << 1); i++, j++) {
			for (int k = i; k < j; k++) {
				if (c[k + 1] == 'x') {
					dp[i][j] = max({
						dp[i][j],
						dp[i][k] * dp[k + 1][j],
						g[i][k] * g[k + 1][j],
						dp[i][k] * g[k + 1][j],
						g[i][k] * dp[k + 1][j]
					});
					g[i][j] = min({
						g[i][j],
						dp[i][k] * dp[k + 1][j],
						g[i][k] * g[k + 1][j],
						dp[i][k] * g[k + 1][j],
						g[i][k] * dp[k + 1][j]
					});
				} else if (c[k + 1] == 't') {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
					g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j]);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i][i + n - 1]);
	printf("%d\n", ans);
	
	for (int i = 1; i <= n; i++)
		if (dp[i][i + n - 1] == ans)
			printf("%d ", i);
	printf("\n");
	
	return 0;
}
