#include <bits/stdc++.h>

using namespace std;

constexpr int N = 207;

int n;
int a[N], dp[N << 1][N << 1];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[i];
	}
	
	for (int i = 2; i <= n + 1; i++) {
		for (int l = 1; l + i - 1 <= (n << 1); l++) {
			int r = l + i - 1;
			for (int k = l + 1; k <= l + i - 2; k++)
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + (a[l] * a[r] * a[k]));
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i][n + i]);

	printf("%d\n", ans);
	return 0;
}
