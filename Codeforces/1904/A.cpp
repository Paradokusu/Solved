#include <bits/stdc++.h>

const int dx[5] = {0, -1, 1, -1, 1};
const int dy[5] = {0, -1, -1, 1, 1};

void solve() {
	int a, b, xk, yk, xq, yq;
	std::cin >> a >> b;
	std::cin >> xk >> yk;
	std::cin >> xq >> yq;

	std::set<std::pair<int, int>> st1, st2;

	for (int i = 1; i <= 4; i++) {
		st1.insert({xk + dx[i] * a, yk + dy[i] * b});
		st2.insert({xq + dx[i] * a, yq + dy[i] * b});
		st1.insert({xk + dx[i] * b, yk + dy[i] * a});
		st2.insert({xq + dx[i] * b, yq + dy[i] * a});
	}

	int ans = 0;

	for (auto i : st1) {
		if (st2.find(i) != st2.end())
			ans++;
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
