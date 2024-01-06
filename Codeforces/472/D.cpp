#include <bits/stdc++.h>

using namespace std;

constexpr int N = 4e3 + 5;
constexpr int inf = 2147483647;

int n, cnt;
int lst[N], dis[N], d[N][N];
bool vis[N];

struct edge {
	int to, val;
};
vector<edge> g[N];

void quit() {
	printf("NO\n");
	exit(0);
}

void Prim() {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0, dis[0] = inf;
	while (true) {
		int u = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dis[i] < dis[u])
				u = i;
		if (!u) break;
		vis[u] = 1;
		if (u != 1) {
			g[u].push_back({lst[u], dis[u]});
			g[lst[u]].push_back({u, dis[u]});
		}
		for (int v = 1; v <= n; v++) {
			if (vis[v]) continue;
			int w = d[u][v];
			if (dis[v] > w)
				dis[v] = w, lst[v] = u;
		}
	}
}

void dfs(int u, int fa) {
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i].to, w = g[u][i].val;
		if (v == fa) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
			if (i != j && d[i][j] == 0) quit();
			if (i == j && d[i][j] != 0) quit();
		}
	}
	Prim();
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		dfs(i, 0);
		for (int j = 1; j <= n; j++)
			if (dis[j] != d[i][j])
				quit();
	}
	printf("YES\n");
	return 0;
}
