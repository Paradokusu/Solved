#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int n, p;
	std::cin >> n >> p;
	std::vector<i64> inv(n + 1);

	inv[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		// i^(-1) = p - (p % i) ^ (-1) * (p / i) % p
		inv[i] = (p - inv[p % i] * (p / i) % p);
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << inv[i] << "\n";
	}
	
	return 0;
}
