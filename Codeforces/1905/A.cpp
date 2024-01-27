#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::cout << std::max(n, m) << "\n";
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
