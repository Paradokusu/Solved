#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> g[n + 1];
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	std::vector<int> d(n + 1);
	int maxd = -inf, stx;
	std::function<void(int, int)> DFSFind1 = [&](int x, int fa) {
		if (d[x] > maxd) maxd = d[x], stx = x;
		for (size_t i = 0; i < g[x].size(); i++) {
			if (g[x][i] == fa) continue;
			d[g[x][i]] = d[x] + 1;
			DFSFind1(g[x][i], x);
		}
	};
	DFSFind1(1, 0);
	std::fill(d.begin(), d.end(), 0);

	maxd = -inf;
	std::vector<int> f(n + 1);
	std::function<void(int, int)> DFSFind2 = [&](int x, int fa) {
		if (d[x] > maxd) maxd = d[x], stx = x;
		for (size_t i = 0; i < g[x].size(); i++) {
			if (g[x][i] == fa) continue;
			d[g[x][i]] = d[x] + 1;
			f[g[x][i]] = x;
			DFSFind2(g[x][i], x);
		}
	};
	DFSFind2(stx, 0);

	int p = stx;
	for (int i = 1; i <= (d[stx] + 1) / 2; i++)
		p = f[p];
	std::fill(d.begin(), d.end(), 0);

	std::vector<int> vd(n + 1);
	std::function<void(int, int)> DFSFind3 = [&](int x, int fa) {
		d[x] = d[fa] + 1, vd[x] = d[x];
		for (size_t i = 0; i < g[x].size(); i++) {
			if (g[x][i] == fa) continue;
			DFSFind3(g[x][i], x);
			vd[x] = std::max(vd[x], vd[g[x][i]]);
		}
	};
	DFSFind3(p, 0);

	std::vector<int> s(n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = vd[i] - d[i];
	std::sort(s.begin() + 1, s.end(), std::greater<int>());

	int ans = -inf;
	for (int i = k + 1; i <= n; i++)
		ans = std::max(ans, s[i] + 1);
	std::cout << ans << "\n";
	return 0;
}
