#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 5;
i64 n, m;
std::vector<bool> vis(N + 5);
std::pair<i64, i64> ans[N + 5];
std::vector<std::array<i64, 3>> g[N];

void dfs(i64 c, i64 x, i64 y) {
	ans[c] = {x, y};
	vis[c] = true;

	for (auto [u, dx, dy] : g[c]) {
		if (vis[u]) continue;
		dfs(u, x + dx, y + dy);
	}
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		i64 a, b, x, y;
		std::cin >> a >> b >> x >> y;
		g[a].push_back({b, x, y});
		g[b].push_back({a, -x, -y});
	}

	dfs(1, 0, 0);

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) std::cout << "undecidable\n";
		else std::cout << ans[i].first << " " << ans[i].second << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
