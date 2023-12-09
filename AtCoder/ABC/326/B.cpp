// Problem: B - 326-like Numbers
// Contest: AtCoder - Panasonic Programming Contest 2023（AtCoder Beginner Contest 326）
// URL: https://atcoder.jp/contests/abc326/tasks/abc326_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	while (n) {
		int tn = n;
		int x = tn % 10;
		tn /= 10;
		int y = tn % 10;
		tn /= 10;
		int z = tn % 10;
		tn /= 10;
		if (y * z == x) {
			std::cout << n << "\n";
			return;
		} else n++;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
