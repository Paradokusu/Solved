#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	if (n % 2 == 1) {
		std::cout << "NO\n";
		return;
	} else {
		std::cout << "YES\n";
		
		for (int i = 1; i <= n / 2; i++)
			for (int j = 1; j <= 2; j++)
				std::cout << "AB"[i & 1];
		
		std::cout << "\n";
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
