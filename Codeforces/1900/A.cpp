#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	int cot = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			cot++;
		}
	}

	if (s.find("...") != -1) {
		std::cout << "2\n";
	} else {
		std::cout << cot << "\n";
	}
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
