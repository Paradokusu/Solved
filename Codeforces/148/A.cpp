#include <bits/stdc++.h>

void solve() {
	int k, l, m, n, d;
	std::cin >> k >> l >> m >> n >> d;
	std::vector<int>a(d + 5);
	int ans = 0;
	for (int i = 1; i <= d; i++) {
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
			ans++;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
