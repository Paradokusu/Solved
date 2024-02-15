#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;
constexpr int M = 2e5 + 7;

int n, m;
int u[M], v[M], ans[M];
int vis[2][N];

vector<int> adj[2][N];

void bfs(int g, int s, int t) {
	queue<int> q;
	vis[g][s] = t;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto y : adj[g][x])
			if (!vis[g][y]) {
				vis[g][y] = t;
				q.push(y);
			}

		adj[g][x].clear();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &u[i], &v[i]);

	for (int i = 1; i <= n; i++) {
		for (int g = 0; g < 2; g++)
			for (int j = 1; j <= n; j++) {
				adj[g][j].clear();
				vis[g][j] = 0;
			}

		vis[0][i] = vis[1][i] = m + 1;

		for (int j = m; j >= 1; j--) {
			if (min(u[j], v[j]) < i)
				continue;

			for (int g = 0; g < 2; g++, swap(u[j], v[j])) {
				if (vis[g][u[j]] && !vis[g][v[j]])
					bfs(g, v[j], j);
				else if (!vis[g][u[j]] && !vis[g][v[j]])
					adj[g][u[j]].push_back(v[j]);
			}
		}

		for (int j = i; j <= n; j++)
			if (vis[0][j] && vis[1][j])
				ans[min(vis[0][j], vis[1][j]) - 1]++;
	}

	for (int i = m; i >= 0; i--)
		ans[i] += ans[i + 1];
	
	for (int i = 0; i <= m; i++)
		printf("%d ", ans[i]);

	printf("\n");
	return 0;
}
