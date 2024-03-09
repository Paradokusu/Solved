#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1, (1 << 30) - 1);
	std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> m[i][j];
			
			if (i != j) {
				a[i] &= m[i][j];
				a[j] &= m[i][j];
			}
		}
	}
	
	bool flg = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && (a[i] | a[j]) != m[i][j]) {
				flg = 0;
			}
		}
	}
	
	if (flg) {
		std::cout << "YES\n";
		
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << " ";
		}
		
		std::cout << "\n";
	} else {
		std::cout << "NO\n";
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
