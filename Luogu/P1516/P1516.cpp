#include <bits/stdc++.h>

using i64 = long long;

i64 x, y, m, n, l, d, k, z;
int f = 1;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	
	i64 d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	
	return d;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> x >> y >> m >> n >> l;
	
	int f = 1;
	
	if (m < n) {	// 防止 m - n < 0
		std::swap(n, m);
		f = -1;
	}
	
	d = exgcd(m - n, l, k, z);	// 求解 k * (m - n) + zl = gcd(m - n, l)
	
	if ((y - x) % d != 0) {	// 无解
		std::cout << "Impossible\n";
		return 0;
	}
	
	k = k * f * (y - x) / d;	// 求解 k * (m - n) + zl = y - x
	k = (k % (l / d) + (l / d)) % (l / d);	// 最小正数 k
	
	std::cout << k << "\n";
	return 0;
}
