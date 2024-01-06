#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e3 + 5;

int n, m, cnt;
int dis[N], num[N];
bool vis[N];

struct edge {
	int to, val;
};

vector<edge> g[N];
queue<int> q;

bool spfa(int x) {
	dis[x] = 0, vis[x] = 1, num[x]++;
	q.push(x);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to, w = g[u][i].val;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1, num[v]++;
					if (num[v] == n + 1) return 0;
				}
			}
		}
	}
	
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(dis, 0x3f, sizeof(dis));
	
	for (int i = 1; i <= m; i++) {
		int opt;
		scanf("%d", &opt);
		if (opt == 1) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back({v, -w});
		} else if (opt == 2) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[v].push_back({u, w});
		} else {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back({v, 0});
			g[v].push_back({u, 0});
		}
	}
	
	for (int i = 1; i <= n; i++)
		g[n + 1].push_back({i, 0});
	
	bool flag = spfa(n + 1);
	if (!flag) printf("No\n");
	else printf("Yes\n");
	return 0;
}
