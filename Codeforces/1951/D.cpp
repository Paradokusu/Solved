#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, k;
	std::cin >> n >> k;
	
	if (n == k) {
		std::cout << "YES\n1\n1\n";
	} else if (k > (n + 1) / 2) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n2\n" << (n - k + 1) << " 1\n";
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
