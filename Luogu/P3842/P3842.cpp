#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> seg(n + 1);
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(2));

	for (int i = 1; i <= n; i++)
		std::cin >> seg[i].first >> seg[i].second;

	f[1][0] = seg[1].second + seg[1].second - seg[1].first - 1;
	f[1][1] = seg[1].second - 1;

	for (int i = 2; i <= n; i++) {
		f[i][0] = std::min(f[i - 1][0] + std::abs(seg[i - 1].first - seg[i].second) + seg[i].second - seg[i].first + 1, f[i - 1][1] + std::abs(seg[i - 1].second - seg[i].second) + seg[i].second - seg[i].first + 1);
		f[i][1] = std::min(f[i - 1][0] + std::abs(seg[i - 1].first - seg[i].first) + seg[i].second - seg[i].first + 1, f[i - 1][1] + std::abs(seg[i - 1].second - seg[i].first) + seg[i].second - seg[i].first + 1);
	}

	std::cout << std::min(f[n][0] + n - seg[n].first, f[n][1] + n - seg[n].second);
	return 0;
}
