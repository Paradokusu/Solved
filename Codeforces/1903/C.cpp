#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n + 1);
	std::vector<i64> suf(n + 2);
	
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = n; i >= 0; i--) {
		suf[i] = suf[i + 1] + a[i];
	}
	
	i64 ans = suf[0];
	
	for (int i = 2; i <= n; i++) {
		if (suf[i] > 0) {
			ans += suf[i];
		}
	}
	
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
