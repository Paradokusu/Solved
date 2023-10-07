#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length(), cnt = 0;
	bool all = (s[0] == 'B' || s[n - 1] == 'B');
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1] && s[i] == 'B')
			all = true;
	std::vector<int> lens;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') cur++;
		else {
			if (cur != 0) lens.push_back(cur);
			cur = 0;
		}
	}
	if (cur != 0) lens.push_back(cur);
	std::sort(lens.begin(), lens.end());
	if (lens.empty()) {
		std::cout << "0\n";
		return;
	}
	int tot = 0;
	if (all) tot += lens[0];
	for (int i = 1; i < lens.size(); i++)
		tot += lens[i];
	std::cout << tot << "\n";
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
