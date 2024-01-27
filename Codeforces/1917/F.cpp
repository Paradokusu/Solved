#include <bits/stdc++.h>

constexpr int N = 2e3 + 7;

void solve() {
	int n, d;
	std::cin >> n >> d;
	std::vector<int> a(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());
	if (a[n] + a[n - 1] > d) {
		std::cout << "No\n";
		return;
	}

	std::vector<std::bitset<N>> dp(d + 1);
	dp[0][0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = d; j >= 0; j--) {
			if (j + a[i] <= d)
				dp[j + a[i]] |= dp[j];
			dp[j] |= (dp[j] << a[i]);
		}
	}

	int ans = dp[0][d - a[n]];
	for (int i = a[n]; i <= d - a[n]; i++)
		if (dp[i][d - i])
			ans = 1;

	if (ans) std::cout << "Yes\n";
	else std::cout << "No\n";
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
