// Problem: B. Paranoid String
// Contest: Codeforces - Codeforces Round 800 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1694/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	s = ' ' + s;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != s[i - 1]) ans += i;
		else ans++;
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
