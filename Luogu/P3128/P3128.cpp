#include <bits/stdc++.h>

struct node {
	int to, nxt;
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<node> edge(n * 4 + 1);
	std::vector<int> head(n * 4 + 1);
	int num = 0;
	std::function<void(int, int)> add = [&](int x, int y) {
		edge[++num].to = y;
		edge[num].nxt = head[x];
		head[x] = num;
	};
	
	for (int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	
	std::vector<int> d(n + 5);
	std::vector<std::vector<int>> fa(n + 5, std::vector<int>(30));
	std::function<void(int, int)> work = [&](int u, int fath) {
		d[u] = d[fath] + 1, fa[u][0] = fath;
		for (int i = 0; fa[u][i]; i++) fa[u][i + 1] = fa[fa[u][i]][i];
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (v != fath) work(v, u);
		}
	};
	work(1, 0);

	std::function<int(int, int)> lca = [&](int u, int v) {
		if (d[u] > d[v]) std::swap(u, v);
		for (int i = 20; i >= 0; i--)
			if (d[u] <= d[v] - (1 << i))
				v = fa[v][i];
		if (u == v) return u;
		for (int i = 20; i >= 0; i--)
			if (fa[u][i] != fa[v][i])
				u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	};

	std::vector<int> power(n + 5);
	while (k--) {
		int x, y;
		std::cin >> x >> y;
		int LCA = lca(x, y);
		++power[x], ++power[y], --power[LCA], --power[fa[LCA][0]];	// 树上差分
	}
	
	int ans = -1e9;
	std::function<void(int, int)> done = [&](int u, int fath) {
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (v == fath) continue;
			done(v, u);
			power[u] += power[v];
		}
		ans = std::max(ans, power[u]);
	};
	done(1, 0);
	std::cout << ans << "\n";
	return 0;
}
