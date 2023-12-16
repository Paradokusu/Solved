#include <bits/stdc++.h>

using i64 = long long;

struct Edge {
	int to, w;
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<Edge> g[n + 5];
	for (int i = 1; i < n; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}

	i64 ans = 0;
	std::vector<i64> size(n + 5);
	std::function<void(int, int)> dfs = [&](int x, int fa) {
		size[x] = 1;
		for (int i = 0; i < g[x].size(); i++) {
			int v = g[x][i].to;
			if (fa == v) continue;
			dfs(v, x);
			size[x] += size[v];
			ans += g[x][i].w * std::abs(2 * size[v] - n);
		}
	};
	dfs(1, 0);

	std::cout << ans << "\n";
	return 0;
}
