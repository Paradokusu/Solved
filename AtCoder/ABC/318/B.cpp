#include <bits/stdc++.h>

void solve() {
	constexpr int N = 105;

	int n;
	std::cin >> n;
	std::vector<std::vector<bool>> ma(N, std::vector<bool>(N));
	std::vector<std::vector<bool>> vis(N, std::vector<bool>(N));
	std::vector<int> a(N), b(N), c(N), d(N);
	int mUp = -N;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i] >> c[i] >> d[i];
		mUp = std::max(mUp, d[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j < b[i]; j++) {
			for (int k = mUp - d[i]; k < mUp - c[i]; k++) {
				ma[j][k] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (ma[i][j] && !vis[i][j])
				ans++, vis[i][j] = true;
	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
