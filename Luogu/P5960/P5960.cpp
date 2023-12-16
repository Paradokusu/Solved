#include <bits/stdc++.h>

constexpr int inf = 2147483647;

struct edge {
	int to, dis;
}; 

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<edge> g[n + 1];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[v].push_back({u, w});
	}

	for (int i = 1; i <= n; i++) {	// 放入源点 0
		g[0].push_back({i, 0});
	}

	std::vector<int> dis(n + 1), vis(n + 1), cnt(n + 1);
	std::function<bool()> spfa = [&]() { 
		std::queue<int> q;
		std::fill(dis.begin(), dis.end(), inf);
		std::fill(vis.begin(), vis.end(), 0);

		q.push(0);
		dis[0] = 0, vis[0] = 1, cnt[0] = 1;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			vis[u] = 0;

			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].to;
				if (dis[v] > 1ll * dis[u] + g[u][i].dis) {
					dis[v] = dis[u] + g[u][i].dis;
					if (vis[v] == 0) {
						vis[v] = 1;
						q.push(v);
						cnt[v]++;
						if (cnt[v] > n + 1) {
							return 1;
						}
					}
				}
			}
		}
		return 0;
	};

	if (!spfa()) {
		for (int i = 1; i <= n; i++) {
			std::cout << dis[i] << " ";
		}
	} else {
		std::cout << "NO";
	}
	std::cout << "\n";
	return 0;
}
