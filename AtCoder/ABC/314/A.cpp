#include <bits/stdc++.h>

void solve() {
	const std::string PI = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

	int n;
	std::cin >> n;
	std::cout << "3.";
	for (int i = 0; i < n; i++)
		std::cout << PI[i];
	std::cout << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
