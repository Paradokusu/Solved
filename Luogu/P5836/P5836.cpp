#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> fa(n + 1);
	std::vector<char> col(n + 1);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		std::cin >> col[i];
	}
	
	std::function<int(int)> find = [&](int x) {
		if (x == fa[x]) {
			return x;			
		}
		return fa[x] = find(fa[x]);
	};
	
	std::function<void(int, int)> merge = [&](int x, int y) {
		fa[find(x)] = find(y);
	};
	
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		if (col[u] == col[v]) {
			merge(u, v);
		}
	}
	
	int cnt = 0;
	std::vector<int> ans(m + 1);
	while (m--) {
		int a, b;
		char c;
		std::cin >> a >> b >> c;
		if (find(a) == find(b) && col[a] != c) {
			ans[++cnt] = 0;
		} else {
			ans[++cnt] = 1;
		}
	}
	
	for (int i = 1; i <= cnt; i++) {
		std::cout << ans[i];
	}
	std::cout << "\n";
	return 0;
}
