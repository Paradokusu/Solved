#include <bits/stdc++.h>

void solve() {
	int n, m, p;
	std::cin >> n >> m >> p;
	int ans = 0;
	for (int i = m; i <= n; i += p)
		ans++;
	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
