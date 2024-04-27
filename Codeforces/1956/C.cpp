#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	long long ans = 0;
	
	for (int i = 1; i <= n; i++)
		ans += ((i << 1) - 1) * i;
	
	std::cout << ans << " " << (n << 1) << "\n";
	
	for (int i = n; i >= 1; i--) {
		std::cout << "1 " << i << " ";
		
		for (int j = 1; j <= n; j++)
			std::cout << j << " ";
		
		std::cout << "\n";
		
		std::cout << "2 " << i << " ";
		
		for (int j = 1; j <= n; j++)
			std::cout << j << " ";
		
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
