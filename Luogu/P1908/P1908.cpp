// Problem: P1908 逆序对
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1908
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 5e5 + 5;

int n, m;
std::array<int, N> a, b, c;

int lowbit(int x) { return x & (-x); }

int Sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += c[i];
	return res;
}

void Add(int x, int y) {
	for (int i = x; i <= m; i += lowbit(i)) c[i] += y;
}

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	std::sort(b.begin() + 1, b.begin() + n + 1);
	m = std::unique(b.begin() + 1, b.begin() + n + 1) - b.begin() - 1;	// 离散化
	long long ans = 0;
	for (int i = n; i; i--) {
		int k = std::lower_bound(b.begin() + 1, b.begin() + m + 1, a[i]) - b.begin();	// 求出当前数的排名
		ans += Sum(k - 1);
		Add(k, 1);
	}
	std::cout << ans << "\n";
	return 0;
}
