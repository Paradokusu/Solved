#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 m;
	std::cin >> n >> m;

	std::map<int, int> mp;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	for (int i = 1, x; i <= n; i++) {
		std::cin >> x;
		mp[a[i]] = x;
	}

	i64 ans = 0;
	for (auto [x, y] : mp) {
		ans = std::max(ans, 1ll * x * std::min(1ll * y, m / x));
		if (mp.contains(x + 1)) {
			int z = mp[x + 1];
			i64 c;
			if (1ll * x * y >= m) {
				c = m / x;
			} else {
				c = y + std::min(1ll * z, (m - 1ll * x * y) / (x + 1));
			}
			ans = std::max(ans, std::min(m, c * x + std::min(1ll * z, c)));
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
