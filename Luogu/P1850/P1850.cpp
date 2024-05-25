#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 7;
constexpr int M = 2e3 + 7;
constexpr double inf = numeric_limits<double>::max();

int n, m, v, e;
int c[N << 1], d[N << 1], a[M][M];
double p[N], f[M][M], dp[M][M][2];

int main() {
	scanf("%d %d %d %d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &p[i]);
	
	for (int i = 1; i <= v; i++)
		for (int j = 1; j < i; j++)
			f[i][j] = f[j][i] = inf;
	
	for (int i = 1; i <= e; i++) {
		int ia, ib, ic;
		scanf("%d %d %d", &ia, &ib, &ic);
		f[ia][ib] = f[ib][ia] = min(f[ia][ib], (double) ic);
	}
	
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++)
			for (int j = 1; j < i; j++)
				if (f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[j][i] = f[i][k] + f[k][j];
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j][0] = dp[i][j][1] = inf;
	
	dp[1][0][0] = dp[1][1][1] = 0;
	
	for (int i = 2; i <= n; i++) {
		double a1 = f[c[i- 1]][c[i]];
		for (int j = 0; j <= min(m, i); j++) {
			dp[i][j][0] = min(dp[i - 1][j][0] + a1, dp[i - 1][j][1] + f[d[i - 1]][c[i]] * p[i - 1] + f[c[i - 1]][c[i]] * (1 - p[i - 1]));
			if (j != 0)
				dp[i][j][1] = min(dp[i - 1][j - 1][0] + f[c[i - 1]][d[i]] * p[i] + f[c[i - 1]][c[i]] * (1 - p[i]), dp[i - 1][j - 1][1] + f[c[i - 1]][c[i]] * (1 - p[i - 1]) * (1 - p[i]) + f[c[i - 1]][d[i]] * (1 - p[i - 1]) * p[i] + f[d[i - 1]][c[i]] * (1 - p[i]) * p[i - 1] + f[d[i - 1]][d[i]] * p[i - 1] * p[i]);
		}
	}
	
	double ans = inf;
	for (int i = 0; i <= m; i++)
		ans = min({ans, dp[n][i][0], dp[n][i][1]});
	printf("%.2lf\n", ans);
	return 0;
}
