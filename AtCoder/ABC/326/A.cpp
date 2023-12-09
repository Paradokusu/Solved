// Problem: A - 2UP3DOWN
// Contest: AtCoder - Panasonic Programming Contest 2023（AtCoder Beginner Contest 326）
// URL: https://atcoder.jp/contests/abc326/tasks/abc326_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

void solve() {
	int x, y;
	std::cin >> x >> y;
	if (x > y) {
		if (x - y <= 3) std::cout << "Yes\n";
		else std::cout << "No\n";
	} else {
		if (y - x <= 2) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
