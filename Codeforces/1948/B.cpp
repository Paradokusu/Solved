#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::vector<int> b({a[n - 1]});
	
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > b.back()) {
			b.push_back(a[i] % 10);
			b.push_back(a[i] / 10);
		} else {
			b.push_back(a[i]);
		}
	}
	
	if (std::is_sorted(b.rbegin(), b.rend()))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
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
