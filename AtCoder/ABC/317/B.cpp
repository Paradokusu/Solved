#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<bool> vis(1050);
	int start = 1e9, end = -1e9;
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		start = std::min(in, start), end = std::max(in, end);
		vis[in] = true;
	}

	for (int i = start; i <= end; i++) {
		if (!vis[i]) {
			std::cout << i << std::endl;
			break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
