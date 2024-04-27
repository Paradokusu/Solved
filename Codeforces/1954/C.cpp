#include <bits/stdc++.h>

void solve() {
	// 差越小，乘积越大
	std::string a, b;
	std::cin >> a >> b;
	
	bool flg = 0;
	
	for (size_t i = 0; i < a.size(); i++) {
		if ((a[i] > b[i]) == flg)
			std::swap(a[i], b[i]);
		
		flg |= (a[i] != b[i]);
	}
	
	std::cout << a << "\n" << b << "\n";
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
