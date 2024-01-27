#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	int sum = 1, neg = 0, zero = 0;

	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		
		if (in < 0) {
			neg++;
		} else if (in == 0) {
			zero++;
		}
	}
	
	if (zero || neg % 2) {
		std::cout << "0\n";
	} else {
		std::cout << "1\n1 0\n";
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
