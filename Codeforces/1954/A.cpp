#include <bits/stdc++.h>

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	
	if ((n - k - 1) * m >= n)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
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
