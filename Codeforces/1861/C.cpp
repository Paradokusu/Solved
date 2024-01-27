#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int cnt = 1, sizea;
		std::vector<int> a;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+') a.push_back(cnt++);
			if (s[i] == '-') a.pop_back();
			if (s[i] == '1') {
				if (a.size() < 2) continue;
				sizea = a.size();
				for (int i = 1; i < a.size(); i++) {
					if (a[i - 1] < a[i]) {
						sort(a.begin(), a.end(), std::greater<int>());
						break;
					}
				}
			}
			if (s[i] == '0') {
				if (a.size() < 2) continue;

			}
		}
		if (a.size() == 1) {
			std::cout << "NO" << std::endl;
		} else if (a.size() == 2) {
			if ()
		}
	}
}
