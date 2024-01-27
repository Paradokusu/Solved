#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;
	std::vector<i64> a(n + 1), f(n + 1);

	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::deque<std::pair<i64, i64>> dq;
	i64 mex = 0, cot = 0;

	for (i64 i = 1; i <= n; i++) {
		f[a[i]]++;
		while (f[mex])
			mex++;
		dq.push_back({mex, 1});
		cot += mex;
	}

	i64 ans = cot;

	for (i64 i = 1; i < n; i++) {
		std::pair<i64, i64> mx = {a[i], 0};
		cot -= dq.front().first;
		dq.front().second--;

		if (dq.front().second == 0) dq.pop_front();

		while (!dq.empty() && dq.back().first >= a[i]) {
			cot -= dq.back().first * dq.back().second;
			mx.second += dq.back().second;
			dq.pop_back();
		}

		dq.push_back(mx);
		cot = cot + mx.first * mx.second;
		dq.push_back({n, 1});
		cot += n;
		ans = std::max(ans, cot);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
