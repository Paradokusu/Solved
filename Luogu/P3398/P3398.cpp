#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> vec[n + 1];
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	std::vector<int> size(n + 1), deep(n + 1), fa(n + 1);
	
	std::function<void(int)> dfs1 = [&](int x) {
		size[x] = 1;
		deep[x] = deep[fa[x]] + 1;
		for (size_t i = 0; i < vec[x].size(); i++) {
			if (fa[x] != vec[x][i]) {
				fa[vec[x][i]] = x;
				dfs1(vec[x][i]);
				size[x] += size[vec[x][i]];
			}
		}
	};
	dfs1(1);
	
	std::vector<int> top(n + 1);
	std::function<void(int)> dfs2 = [&](int x) {
		int t = 0;
		if (!top[x]) {
			top[x] = x;
		}
		
		for (size_t i = 0; i < vec[x].size(); i++) {
			if (fa[x] != vec[x][i] && size[vec[x][i]] > size[t]) {
				t = vec[x][i];
			}
		}
		
		if (t) {
			top[t] = top[x];
			dfs2(t);
		}
		
		for (size_t i = 0; i < vec[x].size(); i++) {
			if (fa[x] != vec[x][i] && vec[x][i] != t) {
				dfs2(vec[x][i]);
			}
		}
	};
	dfs2(1);
	
	std::function<int(int, int)> LCA = [&](int x, int y) {
		for (; top[x] != top[y];) {
			if (deep[top[x]] < deep[top[y]]) {
				std::swap(x, y);
			}
			x = fa[top[x]];
		}
		
		if (deep[x] > deep[y]) {
			std::swap(x, y);
		}
		return x;
	};
	
	while (q--) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		int s = LCA(a, b);
		int t = LCA(c, d);
		if (deep[s] < deep[t]) {
			std::swap(s, t);
			std::swap(a, c);
			std::swap(b, d);
		}
		if (LCA(s, c) == s || LCA(s, d) == s) {
			std::cout << "Y\n";
		} else {
			std::cout << "N\n";
		}
	}
	return 0;
}
