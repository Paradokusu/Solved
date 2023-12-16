#include <bits/stdc++.h>

constexpr int inf = 1e9;

struct edge {
	int to, w;
};

struct node {
	int v, w;
	
	friend bool operator < (const node &a, const node &b) {
		return a.w > b.w;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m, k, s, t;
	std::cin >> n >> m >> k;
	std::cin >> s >> t;
	
	std::vector<edge> g[(n << 8) + 1];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		
		for (int j = 1; j <= k; j++) {
			g[u + j * n].push_back({v + j * n, w});
			g[v + j * n].push_back({u + j * n, w});
			g[u + j * n - n].push_back({v + j * n, 0});
			g[v + j * n - n].push_back({u + j * n, 0});
		}
	}
	
	std::vector<int> dis((n << 8) + 1);
	std::vector<bool> vis((n << 8) + 1);
	std::function<void()> Dijkstra = [&]() {
		std::priority_queue<node> q;
		std::fill(dis.begin(), dis.end(), inf);
		dis[s] = 0;
		
		node t;
		t.v = s, t.w = 0;
		q.push(t);
		
		while (!q.empty()) {
			int u = q.top().v;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (size_t i = 0; i < g[u].size(); i++) {
				if (dis[g[u][i].to] > 1ll * dis[u] + g[u][i].w) {
					dis[g[u][i].to] = dis[u] + g[u][i].w;
					t.w = dis[g[u][i].to], t.v = g[u][i].to;
					q.push(t);
				}
			}
		}
	};
	Dijkstra();
	
	int ans = inf;
	for (int j = 0; j <= k; j++) {
		if (dis[t + j * n] < ans) {
			ans = dis[t + j * n];
		}
	}
	std::cout << ans << "\n";
	return 0;
}
