#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	int ans = 0;
	
	for (int i = 1, inp; i <= n; i++) {
		std::cin >> inp;
		ans = std::__gcd(ans, std::abs(inp));
	}
	
	std::cout << ans << "\n";
	return 0;
}
