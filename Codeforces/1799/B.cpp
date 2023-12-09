// Problem: B. Equalize by Divide
// Contest: Codeforces - Codeforces Round 854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1799/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

struct node {
	int x, y;
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 5);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	if (*std::min_element(a.begin() + 1, a.begin() + n + 1) == *std::max_element(a.begin() + 1, a.begin() + n + 1)) {
		std::cout << "0\n";
		return;
	}
	if (*std::min_element(a.begin() + 1, a.begin() + n + 1) == 1) {
		std::cout << "-1\n";
		return;
	}
	std::vector<node> ans;
	while (*std::min_element(a.begin() + 1, a.begin() + n + 1) != *std::max_element(a.begin() + 1, a.begin() + n + 1)) {
		int p = std::min_element(a.begin() + 1, a.begin() + n + 1) - a.begin(), x = a[p];
		for (int i = 1; i <= n; i++)
			if ((a[i] - 1) / x + 1 > 1)
				a[i] = (a[i] - 1) / x + 1, ans.push_back({i, p});
	}
	std::cout << ans.size() << "\n";
	for (auto i : ans)
		std::cout << i.x << " " << i.y << "\n";
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
