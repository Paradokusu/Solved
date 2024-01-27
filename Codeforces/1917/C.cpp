#include <bits/stdc++.h>

void solve() {
	int n, k, d;
	std::cin >> n >> k >> d;
	std::vector<int> a(n + 1), v(k + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		std::cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i <= std::min(d - 1, 2 * n); i++) {
		int cot = 0;
		for (int j = 1; j <= n; j++) {
			cot += (a[j] == j);
		}

		ans = std::max(ans, cot + (d - i - 1) / 2);
		for (int j = 1; j <= v[i % k + 1]; j++) {
			a[j]++;
		}
	}

	std::cout << ans << "\n";
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
