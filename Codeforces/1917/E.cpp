#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (k % 2) {
		std::cout << "No\n";
		return;
	}

	int t = k % 4;
	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));

	if (k % 4 == 2) {
		if (k >= 6 && k <= n * n - 10) {
			a[0][0] = a[0][2] = a[1][0] = a[1][1] = a[2][1] = a[2][2] = 1;
			k -= 6;
		} else if (k == n * n - 6) {
			a[0][0] = a[0][2] = a[1][0] = a[1][1] = a[2][0] = a[2][1] = a[2][2] = a[2][3] = a[3][0] = a[3][3] = 1;
			k -= 10;
		} else if (n != 2) {
			std::cout << "No\n";
			return;
		} else {
			a[0][0] = a[0][1] = 1;
		}
	}

	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			if (t && i < 4 && j < 4) {
				continue;
			}
			for (auto x : {i, i + 1}) {
				for (int y : {j, j + 1}) {
					a[x][y] = k ? 1 : 0;
				}
			}
			k = std::max(0, k - 4);
		}
	}

	std::cout << "Yes\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
