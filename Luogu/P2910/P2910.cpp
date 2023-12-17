#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> dis[i][j];
		}
	}

	std::function<void()> Floyd = [&]() {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[i][j] = std::min(1ll * dis[i][j], 1ll * dis[i][k] + dis[k][j]);
				}
			}
		}
	};
	Floyd();

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += dis[a[i]][a[i + 1]];
	}

	std::cout << ans << "\n";
	return 0;
}
