#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n;
std::bitset<N> a, flg;
std::string s;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	std::cin >> s;
	s = '#' + s;

	for (int i = 1; i <= n; i++) {
		if (s[i] == '1')
			a[i] = 1, flg[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] && flg[i]) {
			if (i == n - 1)
				a[i + 1] = 1;
			else if (i == n)
				a[i] = 1;
			else
				a[i + 1] = a[i + 2] = 1;
		}
	}

	std::cout << a.count() << "\n";
	return 0;
}
