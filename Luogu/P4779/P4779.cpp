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

	int n, m, s;
	std::cin >> n >> m >> s;
	
	std::vector<edge> g[n + 1];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	
	std::vector<int> dis(n + 1);
	std::vector<bool> vis(n + 1);
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
	
	for (int i = 1; i <= n; i++) {
		std::cout << dis[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
