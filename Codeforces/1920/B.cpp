#include <bits/stdc++.h>

void solve() {
	int n, k, x;
	std::cin >> n >> k >> x;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	std::sort(a.begin() + 1, a.end(), std::greater<int>());
	std::vector<int> s(n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];

	int ans = -1e9;
	for (int i = 0; i <= k; i++) {
		ans = std::max(ans, s[n] - 2 * s[std::min(i + x, n)] + s[i]);
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
