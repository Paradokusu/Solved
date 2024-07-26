#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > 1 && a[i] == 1) {
			std::cout << "-1\n";
			return;
		}
	}

	std::vector<i64> c(n + 1);
	for (int i = 2; i <= n; i++) {
		i64 b = a[i - 1], u = a[i], exr = 0;
		while (b != 1 && b * b <= u) {
			exr--;
			b *= b;
		}
		while (u < b) {
			exr++;
			u *= u;
		}
		c[i] = std::max(0ll, c[i - 1] + exr);
	}

	i64 res = 0;
	for (int i = 1; i <= n; i++)
		res += c[i];
	std::cout << res << "\n";
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
