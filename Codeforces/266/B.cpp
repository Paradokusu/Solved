#include <bits/stdc++.h>

void solve() {
	int n, t;
	std::cin >> n >> t;
	std::string s;
	std::cin >> s;
	std::vector<int> a(n + 5);
	a.assign(a.size(), -1);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') a[i + 1] = 1;
		else if (s[i] == 'G') a[i + 1] = 0;
	}
	while (t--) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && a[i + 1] == 0) {
				std::swap(a[i], a[i + 1]);
				i++;
			}
		}		
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) std::cout << 'B';
		else if (a[i] == 0) std::cout << 'G';
	}
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	solve();
	return 0;
}
