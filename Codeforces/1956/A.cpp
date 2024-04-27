#include <bits/stdc++.h>

void solve() {
	int k, q;
	std::cin >> k >> q;
	std::vector<int> a(k + 1), n(q + 1);
	
	for (int i = 1; i <= k; i++)
		std::cin >> a[i];
	
	for (int i = 1; i <= q; i++) {
		int n;
		std::cin >> n;
		
		std::cout << std::min(a[1] - 1, n) << " ";
	}
	
	std::cout << "\n";
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
