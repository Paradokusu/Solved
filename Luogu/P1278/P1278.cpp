#include <bits/stdc++.h>

constexpr int N = 50;

int n, ans;
std::string v[N];
std::vector<std::vector<int>> f(N, std::vector<int>(1e5 + 5));

int dfs(const int& now, const int& s) {
	if (f[now][s] != -1) return f[now][s];
	f[now][s] = 0;
	for (int i = 0; i < n; i++)
		if (*(v[now].end() - 1) == v[i][0] && (!(s & (1 << i))))
			f[now][s] = std::max(f[now][s], dfs(i, (s | (1 << i))));
	return f[now][s] += v[now].size();
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> v[i];
	for (int i = 0; i < N; i++) std::fill(f[i].begin(), f[i].end(), -1);
	for (int i = 0; i < n; i++) ans = std::max(ans, dfs(i, (1 << i)));
	std::cout << ans << "\n";
	return 0;
}
