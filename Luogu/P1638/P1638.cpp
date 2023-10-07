#include <bits/stdc++.h>

void solve() {
	constexpr int INF = 2e9 + 5;
	int n, m;
	std::cin >> n >> m;
	std::vector<int>a(n + 5);
	std::vector<int>sum(n + 5);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	int l = 1, r = 1, num = 0, ans = INF;
	int ansr, ansl;
	while (l <= r && r <= n + 1) {
		if (num < m) {	// 未满
			r++;
			sum[a[r - 1]]++;
			if (sum[a[r - 1]] == 1) num++;
		} else {
			if (ans > r - l) {		// 更新答案
				ans = r - l;
				ansl = l, ansr = r - 1;
			}	// 尝试缩小费用，往前走
			sum[a[l]]--;
			if (sum[a[l]] == 0) num--;
			l++;
		}
	}
	std::cout << ansl << " " << ansr << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
