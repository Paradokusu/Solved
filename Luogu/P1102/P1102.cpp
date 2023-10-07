#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, c;
	std::cin >> n >> c;
	std::vector<int>s(n + 5);
	for (int i = 0; i < n; i++)
		std::cin >> s[i];
	std::sort(s.begin(), s.begin() + n);
	int l = 0, r = 0;
	i64 sum= 0;
	for (int i = 0; i < n; i++) {
		while (s[l] < s[i] - c && l < n) l++;
		while (s[r] <= s[i] - c && r < n) r++;
		if (s[i] - s[l] == c) sum += (r - l);
	}
	std::cout << sum << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
