#include <bits/stdc++.h>

int n, m, tot, ans;
std::vector<int> c, v;

bool dfs(int x, int num) {	// 奶牛号码和车厢数目
	for (int i = 1; i <= x && i <= num; i++) {
		if (v[i] + c[x] <= m) {
			v[i] += c[x];
			if (x == n) return 1;
			if (dfs(x + 1, num)) return 1;
			v[i] -= c[x];
		}
	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin>> n >> m;
	c.resize(n + 5), v.resize(n + 5);
	for (int i = 1; i <= n; i++) std::cin >> c[i];
	for (int i = 1; i <= n; i++) {
		fill(v.begin() + 1, v.begin() + n + 1, 0);
		if (dfs(1, i)) { std::cout << i << "\n"; break; }
	}
	return 0;
}
