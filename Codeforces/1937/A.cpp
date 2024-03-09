#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	int pos = 1;
	
	while (pos * 2 <= n) {
		pos *= 2;
	}
	
	std::cout << pos << "\n";
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
