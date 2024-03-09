#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	
	std::set<std::pair<int, int>> pst;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1 && a[j] < a[i] && a[i] <= b[j]; j--)
			pst.insert({j, a[i]});
		
		for (int j = i + 1; j <= n && a[j] < a[i] && a[i] <= b[j]; j++)
			pst.insert({j, a[i]});
	}
	
	bool flg = 1;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i])
			if (!pst.count({i, b[i]})) {
				flg = 0;
				break;
			}
	}
	
	std::cout << (flg ? "YES" : "NO") << "\n";
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
