#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

int T, n, m;
int a[N][N], dp[N][N];

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	
	int ans = 1, g = __gcd(a[1][1], a[n][m]);
	for (int x = 1; x * x <= g; x++) {
		if (g % x) continue;
		vector<int> d = {x, g / x};
		
		for (auto dt : d) {
			memset(dp, 0, sizeof(dp));
			dp[1][1] = 1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (a[i][j] % dt) continue;
					if (!dp[i][j] && i != 1)
						dp[i][j] = (dp[i - 1][j] == 1 ? 1 : 0);
					if (!dp[i][j] && j != 1)
						dp[i][j] = (dp[i][j - 1] == 1 ? 1 : 0);
				}
			}
			if (dp[n][m])
				ans = max(ans, dt);
		}
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
