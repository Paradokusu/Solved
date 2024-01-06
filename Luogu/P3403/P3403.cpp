#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 5;
constexpr i64 inf = 1e18;

int x, y, z;
i64 h, ans, d[N];
bool v[N];

vector<pair<int, int>> e[N];
priority_queue<pair<i64, int>> q;

int main() {
	scanf("%lld", &h);
	scanf("%d %d %d", &x, &y, &z);
	
	for (int i = 0; i < x; i++) {
		e[i].push_back({(i + y) % x, y});
		e[i].push_back({(i + z) % x, z});
		d[i] = inf;
	}
	
	d[0] = 0;
	q.push({0, 0});
	
	while (!q.empty()) {
		int x_ = q.top().second;
		q.pop();
		if (v[x_]) continue;
		v[x_] = 1;
		for (size_t i = 0; i < e[x_].size(); i++) {
			int y_ = e[x_][i].first, z_ = e[x_][i].second;
			if (d[y_] > d[x_] + z_) {
				d[y_] = d[x_] + z_;
				q.push({-d[y_], y_});
			}
		}
	}
	
	h -= 1;
	
	for (int i = 0; i < x; i++)
		if (h >= d[i])
			ans += (h - d[i]) / x + 1;

	printf("%lld\n", ans);
	return 0;
}
