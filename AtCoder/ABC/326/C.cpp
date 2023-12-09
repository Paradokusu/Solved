// Problem: C - Peak
// Contest: AtCoder - Panasonic Programming Contest 2023（AtCoder Beginner Contest 326）
// URL: https://atcoder.jp/contests/abc326/tasks/abc326_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 INF = 1e18;

void solve() {
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n + 5);
	for (i64 i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort(a.begin() + 1, a.begin() + n + 1);
	a[n + 1] = INF;
	i64 ans = -INF;
	i64 r = 1;
	for (i64 i = 1; i <= n; i++) {
		while (a[r] < a[i] + m)
			r++;
		ans = std::max(ans, r - i);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
