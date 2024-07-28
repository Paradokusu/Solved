#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		s = '$' + s;
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	if (n == k) {
		std::cout << a[1][1] << "\n";
		return;
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				std::cout << a[i][j];
			std::cout << "\n";
		}
		return;
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		std::cout << a[i][j] << " ";
	// 	std::cout << "\n";
	// }
	std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i += k) {
		int cot = 1;
		for (int p = 1; p <= n; p += k) {
			// g[i][cot] = a[i][p];
			// cot++;
			std::cout << a[i][p];
		}
		std::cout << "\n";
	}

	// for (int i = 1; i <= n / k; i++) {
	// 	for (int j = 1; j <= n / k; j++)
	// 		std::cout << g[i][j];
	// 	std::cout << "\n";
	// }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
