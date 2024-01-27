#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	int ans = 0;
	for (int k = 1; k <= n; k++) {
		if (n % k == 0) {
			int gcd = 0;
			for (int i = 1; i + k <= n; i++) {
				gcd = std::__gcd(gcd, std::abs(a[i + k] - a[i]));
			}
			ans += (gcd != 1);
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
