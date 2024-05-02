#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	i64 S;
	
	std::cin >> n >> m >> S;
	
	i64 W = S;
	
	i64 x, y;
	std::vector<i64> w((n + m) << 1), v((n + m) << 1);	// 价值和重量
	
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> v[i];
		y = std::max(y, w[i]);
	}
	
	x = 1, y++;
	std::vector<i64> l((n + m) << 1), r((n + m) << 1);

	for (int i = 1; i <= m; i++)
		std::cin >> l[i] >> r[i];
	
	i64 sum, mid;
	
	while (x < y) {
		std::vector<i64> sw((n + m) << 1), sv((n + m) << 1);	// 价值前缀和、数量前缀和
		mid = (x + y) >> 1;
		sum = 0;
		
		for (int i = 1; i <= n; i++) {
			if (w[i] >= mid) {	// 合格品计入统计
				sw[i] = sw[i - 1] + 1;
				sv[i] = sv[i - 1] + v[i];
			} else {
				sw[i] = sw[i - 1];
				sv[i] = sv[i - 1];
			}
		}	// sv: 记录 w[i] 符合条件的 v[i] 的前缀和

		for (int i = 1; i <= m; i++)	// 求每一段区间的检验值
			sum += (sw[r[i]] - sw[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]);

		if (sum == S) {
			W = 0;
			break;	// 刚好为标准值
		}

		W = std::min(W, std::abs(sum - S));	// 更新答案

		if (sum <= S)
			y = mid;	// y 值太小，则二分左区间以减少 W 值
		else if (sum > S)
			x = mid + 1;
	}
	
	std::cout << W << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	solve();
	return 0;
}
