#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 998244353;

i64 expow(i64 a, i64 b) {
	i64 res = 1 % MOD;

	for (; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
	}

	return res;
}

void solve() {
	i64 n;
	std::cin >> n;
	std::map<i64, std::pair<i64, i64>> Map;
	Map[1] = {1, 0};

	std::function<std::pair<i64, i64>(i64)> calc = [&](i64 n) {
		if (Map.find(n) != Map.end())
			return Map[n];
		auto [lk, lb] = calc((n + 1) / 2);
		auto [rk, rb] = calc(n / 2);
		/* i64 lk, lb, rk, rb;
		std::tie(lk, lb) = calc((n + 1) / 2);
		std::tie(rk, rb) = calc(n / 2); */
		i64 t = (expow(2, (n + 1) / 2) - 1) * (expow(2, n / 2) - 1) % MOD;
		i64 k = (t + 2 * lk + 2 * rk) % MOD;
		i64 b = (lb + rk + rb) % MOD;

		return Map[n] = {k % MOD, b % MOD};
	};

	auto [k, b] = calc(n);
	std::cout << (k + b) % MOD << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
