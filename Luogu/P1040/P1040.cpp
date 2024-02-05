#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 30;

int n;
int a[N << 2], g[N << 2][N << 2];
i64 dp[N << 2][N << 2];

i64 dfs(int i, int j) {
	if (i == j) {
		g[i][j] = i;
		return (i64) a[i];
	}
	
	if (dp[i][j] != -1)
		return dp[i][j];
	
	i64 ans = 0;
	for (int k = i; k <= j; k++) {
		if ((k - 1 < i ? 1 : dfs(i, k - 1)) * (k + 1 > j ? 1 : dfs(k + 1, j)) + a[k] > ans) {
			g[i][j] = k;
			ans = (k - 1 < i ? 1 : dfs(i, k - 1)) * (k + 1 > j ? 1 : dfs(k + 1, j)) + a[k];
		}
	}
	
	return dp[i][j] = ans;
}

void PreOrder(int i, int j) {
	if (j < i) return;
	printf("%d ", g[i][j]);
	if (g[i][j] - 1 >= i)
		PreOrder(i, g[i][j] - 1);
	if (g[i][j] + 1 <= j)
		PreOrder(g[i][j] + 1, j);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", dfs(1, n));
	PreOrder(1, n);
	return 0;
}
