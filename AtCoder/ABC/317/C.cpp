#include <bits/stdc++.h>

const int N = 15;
const int M = 50;

int n, m, ans = -1e9;

int e[M + 5][M + 5];
int vis[N + 5];

void dfs(int pos, int sum) {
	vis[pos] = 1;

	ans = std::max(sum, ans);
	for (int i = 1; i <= n; i++)
		if (e[pos][i] && !vis[i])
			dfs(i, sum + e[pos][i]);

	vis[pos] = 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
	}
	for (int i = 1; i <= n; i++)
		dfs(i, 0);
	std::cout << ans << "\n";
	return 0;
}
