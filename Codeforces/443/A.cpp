#include <bits/stdc++.h>

void solve() {
	char c;
	std::map<char, bool> ma;
	int ans = 0;
	while (std::cin >> c) {
		if (c <= 'z' && c >= 'a') {
			if (ma[c]) continue;
			else ans++, ma[c] = true;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
