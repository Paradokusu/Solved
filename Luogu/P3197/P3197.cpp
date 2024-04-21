#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 100003;

i64 expow(i64 a, i64 b) {
	i64 res = 1 % MOD;
	
	for (; b; b >>= 1) {
		if (b & 1)
			res = 1ll * res * a % MOD;

		a = 1ll * a * a % MOD;
	}
	
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 n, m;
	std::cin >> m >> n;
	
	i64 all = expow(m, n);
	i64 no = 1ll * m * expow(m - 1, n - 1) % MOD;
	i64 ans = (all - no) % MOD;

	if (ans < 0)
		ans += MOD;
	
	std::cout << ans << "\n";
	return 0;
}
