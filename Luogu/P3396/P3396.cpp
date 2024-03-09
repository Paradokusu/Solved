#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(n + 1);
	std::vector<std::vector<int>> ans(500 + 1, std::vector<int>(500 + 1));
	
	int siz = std::pow(n, 1 / 3);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		
		for (int p = 1; p <= siz; p++)
			ans[p][i % p] += a[i];
	}
	
	while (m--) {
		char opt;
		int x, y;
		std::cin >> opt >> x >> y;
		
		if (opt == 'A') {
			if (x <= siz) {
				std::cout << ans[x][y] << "\n";
			} else {
				int res = 0;
				
				for (int i = y; i <= n; i += x) {
					res += a[i];
				}
				
				std::cout << res << "\n";
			}
		} else if (opt == 'C') {
			for (int p = 1; p <= siz; p++) {
				ans[p][x % p] -= (a[x] - y);
			}
			a[x] = y;
		}
	}
	
	return 0;
}
