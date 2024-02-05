#include <bits/stdc++.h>

using namespace std;

constexpr int N = 57;
constexpr int inf = 1e9;

int n, m, dis[N][N];
bool g[N][N], f[N][N][N];

void dp() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j])
				f[0][i][j] = 1;
	
	for (int i = 1; i <= 30; i++)
		for (int k = 1; k <= n; k++)
			for (int u = 1; u <= n; u++)
				for (int v = 1; v <= n; v++)
					f[i][u][v] |= f[i - 1][u][k] & f[i - 1][k][v];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x][y] = 1;
	}
	
	dp();
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	
	for (int i = 0; i <= 30; i++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				if (f[i][u][v])
					dis[u][v] = min(dis[u][v], 1);
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (k != i && k != j && i != j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	printf("%d\n", dis[1][n]);
	return 0;
}
