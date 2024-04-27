#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int bgn = -1, ans = n;
	
	for (int i = 0; i < n; i++)
		if (a[i] != a[0]) {
			ans = std::min(ans, i - bgn - 1);
			bgn = i;
		}
	
	ans = std::min(ans, n - bgn - 1);
	
	if (ans == n)
		std::cout << "-1\n";
	else
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
