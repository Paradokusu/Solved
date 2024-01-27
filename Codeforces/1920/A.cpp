#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> q(n + 1);
	
	int l = -1e9, r = 1e9;
	for (int i = 1; i <= n; i++) {
		int a, x;
		std::cin >> a >> x;
		if (a == 1) {
			l = std::max(l, x);
		} else if (a == 2) {
			r = std::min(r, x);
		} else if (a == 3) {
			q.push_back(x);
		}
	}

	if (r < l) {
		std::cout << "0\n";
		return;
	}

	int tot = 0;
	for (int i = 0; i < q.size(); i++) {
		if (q[i] <= r && l <= q[i])
			tot++;
	}

	std::cout << r - l + 1 - tot << "\n";
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
