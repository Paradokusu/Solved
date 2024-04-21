#include <bits/stdc++.h>

using i64 = long long;

i64 expow(i64 a, i64 b) {
	i64 res = 1;
	
	for (; b; b >>= 1) {
		if (b & 1)
			res = 1ll * res * a;

		a = 1ll * a * a;
	}
	
	return res;
}

i64 C(i64 a, i64 b) {	// 求组合数
	if (a < b)
		return 0;
	
	i64 res = 1;
	
	for (i64 i = a; i > a - b; i--) {
		res *= i;
		res /= (a - i + 1);
	}
	
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 n, r;
	std::cin >> n >> r;
	i64 ans = 0;
	
	for (i64 k = 0; k <= r - 1; k++) {
		ans += ((k & 1) ? - 1 : 1) * C(r, k) * expow(r - k, n);
	}
	
	std::cout << ans << "\n";
	return 0;
}
