#include <bits/stdc++.h>

using namespace std;
constexpr int N = 105;
constexpr int inf = 1e9;

int n, m;
int g[N][N], f[N][N];

void reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = f[i][j];
}

int main() {
	scanf("%d %d", &n, &m);
	memset(g, 0x3f, sizeof(g));
	
	while (m--) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = g[y][x] = w;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				f[i][j] = g[i][j];
			}
		}
	}
	
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			g[i][j] = g[j][i] = 0;
			for (int k1 = 1; k1 <= n; k1++)
				for (int k2 = 1; k2 <= n; k2++)
					g[k1][k2] = min(g[k1][k2], g[k1][i] + g[i][k2]);
			for (int k1 = 1; k1 <= n; k1++)
				for (int k2 = 1; k2 <= n; k2++)
					g[k1][k2] = min(g[k1][k2], g[k1][j] + g[j][k2]);
			int res = 0;
			for (int k1 = 1; k1 <= n; k1++)
				for (int k2 = 1; k2 < k1; k2++)
					res += g[k1][k2];
			ans = min(ans, res);
			reset();
		}
	}
	printf("%d\n", ans);
	return 0;
}
