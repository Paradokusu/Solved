#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 l, r, ans;
	std::cin >> l >> r;
	
	ans = ((l + r) % 9 * (r - l + 1) % 9 * 5) % 9;
	
	std::cout << ans << "\n";
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
