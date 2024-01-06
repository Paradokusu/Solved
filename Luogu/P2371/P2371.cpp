#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 5;
constexpr i64 inf = 1e18;

int n, x;
i64 l, r, ans, d[N];
bool v[N];

vector<pair<int, int>> e[N];
priority_queue<pair<i64, int>> q;

int main() {
	scanf("%d %lld %lld %d", &n, &l, &r, &x);
	
	l -= 1;
	
	for (int i = 1; i < x; i++) d[i] = inf;
	
	for (int i = 1, y; i < n; i++) {
		scanf("%d", &y);
		for (int i = 0; i < x; i++)
			e[i].push_back({(i + y) % x, y});
	}
	
	q.push({0, 0});

	while (!q.empty()) {
		int x_ = q.top().second;
		q.pop();
		if (v[x_]) continue;
		v[x_] = 1;
		for (size_t i = 0; i < e[x_].size(); i++) {
			int y = e[x_][i].first, z = e[x_][i].second;
			if (d[y] > d[x_] + z) {
				d[y] = d[x_] + z;
				q.push({-d[y], y});
			}
		}
	}
	
	for (int i = 0; i < x; i++) {
		if (r >= d[i]) ans += (r - d[i]) / x + 1;
		if (l >= d[i]) ans -= (l - d[i]) / x + 1;
	}
	
	printf("%lld\n", ans);
	return 0;
}
