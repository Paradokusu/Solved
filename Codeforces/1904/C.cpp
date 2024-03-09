#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<i64> a(n + 1);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	if (k >= 3) {
		std::cout << "0\n";
		return;
	}
	
	std::sort(a.begin() + 1, a.end());
	i64 dif = a[1];
	
	for (int i = 1; i <= n - 1; i++) {
		dif = std::min(dif, a[i + 1] - a[i]);
	}
	
	if (k == 1) {
		std::cout << dif << "\n";
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			i64 v = a[i] - a[j];
			i64 p = std::lower_bound(a.begin() + 1, a.end(), v) - a.begin();
			
			if (p < n) {
				dif = std::min(dif, a[p] - v);
			}
			
			if (p > 1) {
				dif = std::min(dif, v - a[p - 1]);
			}
		}
	}
	
	std::cout << dif << "\n";
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
