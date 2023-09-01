#include <bits/stdc++.h>

void solve() {
	int n, h, x;
	std::cin >> n >> h >> x;
	std::vector<int> a(n + 5);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	std::vector<int> b(n + 5);
	for (int i = 1; i <= n; i++) {
		if (a[i] + h >= x) {
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
