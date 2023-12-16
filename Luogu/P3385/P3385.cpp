#include <bits/stdc++.h>

constexpr int inf = 1e9;

struct edge {
	int to, dis;
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> dis(n + 1), vis(n + 1), cnt(n + 1);
	std::vector<edge> g[n + 5];
	std::function<bool()> spfa = [&]() {
		std::queue<int> q;
		for (int i = 1; i <= n; i++) {
			dis[i] = inf;
			vis[i] = 0;
		}
		
		q.push(1);
		dis[1] = 0, vis[1] = 1;
		cnt[1]++;
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for (size_t i = 0; i < g[u].size(); i++) {
				int v = g[u][i].to;
				if (dis[v] > 1ll * dis[u] + g[u][i].dis) {
					dis[v] = dis[u] + g[u][i].dis;
					if (vis[v] == 0) {
						vis[v] = 1;
						q.push(v);
						cnt[v]++;
						if(cnt[v] > n) {
							return 1;
						}
					}
				}
			}
		}
		return 0;
	};
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		if (w >= 0) {
			g[v].push_back({u, w});
		}
	}

	if (spfa()) std::cout << "YES\n";
	else std::cout << "NO\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
