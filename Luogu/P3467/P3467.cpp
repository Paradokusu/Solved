#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	constexpr i64 N = 250000;
	std::vector<i64> s(N + 5);
	i64 n, top = 0;
	std::cin >> n;
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 t, x;
		std::cin >> t >> x;
		while (x <= s[top]) {
			if (x == s[top]) ans++;
			top--;
		}
		s[++top] = x;
	}
	std::cout << n - ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
