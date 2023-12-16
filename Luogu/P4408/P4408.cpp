#include <bits/stdc++.h>

using i64 = long long;

struct edge {
	int to, w;
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
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	int st = 0;
	std::vector<i64> dis1(n + 1);
	std::function<void(int, int)> dfs1 = [&](int u, int fa) {
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to;
			if (v == fa) continue;
			dis1[v] = dis1[u] + g[u][i].w;
			if (dis1[v] > dis1[st]) st = v;
			dfs1(v, u);
		}
	};
	dfs1(1, 0);
	
	int ed = 0;
	std::vector<i64> dis2(n + 1);
	std::function<void(int, int)> dfs2 = [&](int u, int fa) {
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to;
			if (v == fa) continue;
			dis2[v] = dis2[u] + g[u][i].w;
			if (dis2[v] > dis2[ed]) ed = v;
			dfs2(v, u);
		}
	};
	dfs2(st, 0);
	
	i64 ans = dis2[ed];
	std::fill(dis1.begin(), dis1.end(), 0);
	std::fill(dis2.begin(), dis2.end(), 0);
	
	std::function<void(int, int)> dfs3 = [&](int u, int fa) {
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to;
			if (v == fa) continue;
			dis1[v] = dis1[u] + g[u][i].w;
			dfs3(v, u);
		}
	};
	dfs3(st, 0);
	
	std::function<void(int, int)> dfs4 = [&](int u, int fa) {
		for (size_t i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to;
			if (v == fa) continue;
			dis2[v] = dis2[u] + g[u][i].w;
			dfs4(v, u);
		}
	};
	dfs4(ed, 0);
	
	i64 k = 0;
	for (int i = 1; i <= n; i++) {	// C
		i64 d = std::min(dis1[i], dis2[i]);
		if (d > k) {
			k = d;
		}
	}
	
	ans += k;
	std::cout << ans << "\n";
	return 0;
}
