#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	if (std::is_sorted(a.begin() + 1, a.end()) || k > 1) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
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
