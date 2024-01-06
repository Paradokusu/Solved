#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;
constexpr int M = 5e5 + 5;

struct node {
	int to, val;
};

int n, m, tot;
int cost[N], h[N << 2], d[N << 2];
bool vis[N << 2];
vector<node> g[N * 2 + M * 6];

void SPFA(int s) {
	memset(d, 0x80, sizeof(d));
	memset(vis, 1, sizeof(vis));

	queue<int> q;
	q.push(s);
	d[s] = 0;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 1;
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to, w = g[u][i].val;
			if (d[v] < d[u] + w) {
				d[v] = d[u] + w;
				if (vis[v]) {
					vis[v] = 0;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		g[i].push_back({i + n, -cost[i]});
		g[i + n].push_back({i + 2 * n, cost[i]});
	}
	for (int i = 1; i <= m; i++) {
		int u, v, z;
		scanf("%d %d %d", &u, &v, &z);
		g[u].push_back({v, 0});
		g[u + n].push_back({v + n, 0});
		g[u + 2 * n].push_back({v + 2 * n, 0});
		if (z == 2) {
			g[v].push_back({u, 0});
			g[v + n].push_back({u + n, 0});
			g[v + 2 * n].push_back({u + 2 * n, 0});
		}
	}
	SPFA(1);
	printf("%d\n", max(d[n], d[3 * n]));
	return 0;
}
