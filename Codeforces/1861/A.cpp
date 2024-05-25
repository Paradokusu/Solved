#include <bits/stdc++.h>

bool isPrime(int x) {
	if (x == 0 || x == 1) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void solve() {
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		bool flag = false;
		std::vector<int> a(15);
		int pos = 1;
		for (int i = 0; i < s.size(); i++)
			a[pos++] = s[i] - '0';
		for (int i = 1; i <= pos - 2; i++) {
			if (flag) break;
			for (int j = i + 1; j <= pos - 1; j++) {
				if (isPrime(a[i] * 10 + j)) {
					std::cout << a[i] * 10 + j << std::endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag) std::cout << "-1" << std::endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
