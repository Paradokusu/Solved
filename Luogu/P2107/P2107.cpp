#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	i64 n, m;
	std::cin >> n >> m;
	std::vector<std::pair<i64, i64>> a(n + 1);
	
	for (i64 i = 1; i <= n; i++) {
		i64 x, y;
		std::cin >> x >> y;
		a[i] = {x, y};
	}
	
	std::sort(a.begin() + 1, a.end());
	i64 ans = 0, nowt = 0, prob = 0;
	
	std::priority_queue<std::pair<i64, i64>> q;
	
	for (i64 i = 1; i <= n; i++) {
		nowt += a[i].first - a[i - 1].first;
		q.push({a[i].second, a[i].first});
		++prob;
		nowt += a[i].second;
		
		if (nowt > m) {
			while (nowt > m && !q.empty()) {	// 反悔
				prob--;
				nowt -= q.top().first;
				q.pop();
			}
		}
		
		if (nowt > m) {
			break;
		}
		
		ans = std::max(ans, prob);
	}
	
	std::cout << ans << "\n";
	return 0;
}
