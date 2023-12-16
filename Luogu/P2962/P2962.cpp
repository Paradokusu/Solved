#include <bits/stdc++.h>

using i64 = long long;

int n, k, ans = 1e9;
i64 twn;
std::vector<i64> v(45);
std::unordered_map<i64, int> m;

void Add(int x, int y) {
	v[x] = v[x] ^ 1 << y;
	v[y] = v[y] ^ 1 << x;
}

void dfs(int x, int u, i64 k, int t) {
	if (m[k]) m[k] = std::min(m[k], t);
	else m[k] = t;

	if (m[k ^ twn] || k == twn) ans = std::min(ans, m[k ^ twn] + t);

	if (x <= u) {
		dfs(x + 1, u, k, t);	// 不改
		k ^= v[x];
		dfs(x + 1, u, k, t + 1);	// 改 
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		i64 a, b;
		std::cin >> a >> b;
		Add(a, b);
	}
	
	for (int i = 1; i <= n; i++) {
		v[i] = v[i] ^ 1 << i;	// 自身变化
		twn = twn ^ 1 << i;
	}
	
	// Meet in the Middle
	dfs(1, n / 2, 0, 0);
	dfs(n / 2 + 1, n, 0, 0);
	
	std::cout << ans << "\n";
	return 0;
}
