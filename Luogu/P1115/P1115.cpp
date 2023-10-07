#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	constexpr int INF = -1e4;
	i64 n, f = 0, ans = INF;
	std::cin >> n;
	for (i64 i = 1, in; i <= n; i++) {
		std::cin >> in;
		f = std::max(in, f + in);
		ans = std::max(ans, f);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
