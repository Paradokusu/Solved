#include <bits/stdc++.h>

void solve() {
	constexpr int N = 650;
	std::vector<int>t(N);	// 桶排，空间换时间
	int n, w;
	std::cin >> n >> w;
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		t[in]++;
		int sum = 0;	// 人数
		for (int j = 600; j >= 0; j--) {
			sum += t[j];
			if (sum >= std::max(1, i * w / 100)) {
				std::cout << j << " ";
				break;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
