#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	s = '#' + s;
	std::vector<int> sub;

	for (int i = 1; i <= n; i++) {
		while (!sub.empty() && s[sub.back()] < s[i])
			sub.pop_back();
		sub.push_back(i);
	}

	int cot = 0, m = sub.size() - 1;

	while (cot <= m && s[sub[cot]] == s[sub[0]])
		cot++;

	cot = m - cot + 1;

	for (int i = 0; i <= m; i++) {
		if (i < m - i)
			std::swap(s[sub[i]], s[sub[m - i]]);
	}

	for (int i = 2; i <= n; i++) {
		if (s[i] < s[i - 1]) {
			cot = -1;
			break;
		}
	}

	std::cout << cot << "\n";
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
