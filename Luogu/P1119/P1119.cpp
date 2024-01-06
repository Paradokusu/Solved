#include <bits/stdc++.h>

using namespace std;

constexpr int N = 205;

int n, m, q;
int fix[N], dis[N][N][N];

void input(){
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &fix[i]);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		dis[0][u][v] = dis[0][v][u] = w;
	}
}

void prework() {
	for (int i = 0; i < n; i++) dis[0][i][i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[0][i][j] = min(dis[0][i][j], dis[0][i][0] + dis[0][0][j]);
	for (int k = 1; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[k][i][j] = min(dis[k - 1][i][j], dis[k - 1][i][k] + dis[k - 1][k][j]);
}

void solve() {
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		int ft = upper_bound(fix, fix + n, t) - fix - 1;
		printf("%d\n", (t < fix[u] || t < fix[v] || dis[ft][u][v] == 0x3f3f3f3f) ? -1 : dis[ft][u][v]);
	}
}

int main() {
	input();
	prework();
	solve();
	return 0;
}
