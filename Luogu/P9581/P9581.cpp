#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int a, b;
	std::cin >> a >> b;
	if (std::min(a, b) < 0 && std::max(a, b) > 0) {
		std::cout << std::abs(a) + std::abs(b) + std::min(std::abs(a), std::abs(b)) << std::endl;
	} else {
		std::cout << std::max(std::abs(a), std::abs(b)) << std::endl;
	}
	return 0;
}
