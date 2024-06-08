#include <bits/stdc++.h>

using namespace std;

constexpr int N = 507;

int n, m;
int vis[N], l[N][N];
vector<int> e1[N << 1], e2[N << 1];

bool dfs(int u, int col) {
	vis[u] = col;
	for (auto v : e2[u]) {
		if (vis[u] == vis[v]) return 0;
		if (vis[v] != -1) continue;
		if (!dfs(v, col ^ 1)) return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e1[u].push_back(v);
		e1[v].push_back(u);
		l[u][v] = l[v][u] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (!l[i][j] && (i != j))
				e2[i].push_back(j);
	}
	
	memset(vis, -1, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (!e2[i].empty() && vis[i] == -1) {
			if (!dfs(i, 0)) {
				printf("No\n");
				exit(0);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (auto j : e1[i]) {
			if ((vis[j] == 0 && vis[i] == 1) || (vis[j] == 1 && vis[i] == 0)) {
				printf("No\n");
				exit(0);
			}
		}
	}
	
	printf("Yes\n");
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) printf("a");
		else if (vis[i] == 1) printf("c");
		else printf("b");
	}
	printf("\n");
	
	return 0;
}

