#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e3 + 7;
constexpr i64 inf = 1e18;

int n, m, top;
int a[N], stc[N];
i64 ans = inf, dp[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1, greater<int>());
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	
	for (int i = 1; i <= m; i++) {
		stc[top = 1] = i - 1;
		for (int j = i; j <= n; j++) {
			while (top > 1 && dp[i - 1][stc[top]] - dp[i - 1][stc[top - 1]] >= 1ll * a[j] * (stc[top] - stc[top - 1]))
				--top;
			dp[i][j] = dp[i - 1][stc[top]] + 1ll * a[j] * (j - stc[top]);
			while (top > 1 && (dp[i - 1][j] - dp[i - 1][stc[top - 1]]) * (stc[top] - stc[top - 1]) <= (dp[i - 1][stc[top]] - dp[i - 1][stc[top - 1]]) * (j - stc[top - 1]))
				--top;
			stc[++top] = j;
		}
	}
	
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[m][i]);

	printf("%lld\n", ans);
	return 0;
}
