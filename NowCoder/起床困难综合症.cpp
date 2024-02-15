#include <bits/stdc++.h>

constexpr int arrn = 1e6 + 5;

int n, m;
std::vector<std::pair<std::string, int>> a(arrn);

int calc(int bit, int now) {	// 用参数的第 bit 位进行 n 次运算
	for (int i = 1; i <= n; i++) {
		int x = a[i].second >> bit & 1;
		if (a[i].first == "AND") now &= x;
		else if (a[i].first == "OR") now |= x;
		else if (a[i].first == "XOR") now ^= x;
	}
	return now;
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char str[5];
		int x;
		std::cin >> str >> x;
		a[i] = std::make_pair(str, x);
	}
	int val = 0, ans = 0;
	for (int bit = 29; bit >= 0; bit--) {
		int res0 = calc(bit, 0);
		int res1 = calc(bit, 1);
		if (val + (1 << bit) <= m && res0 < res1)
			val += 1 << bit, ans += res1 << bit;
		else
			ans += res0 << bit;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	solve();
	return 0;
}
