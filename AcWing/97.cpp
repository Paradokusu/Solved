#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 MOD = 9901;

std::unordered_map<i64, i64> primes;

void divide(i64 n) {
	for (i64 i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				primes[i]++;
				n /= i;
			}
		}
	}
	if (n > 1) primes[n]++;
}

i64 power(i64 a, i64 b) {
	i64 ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = 1ll * ans * a % MOD;
		a = 1ll * a * a % MOD;
	}
	return ans;
}

i64 sum(i64 p, i64 k) {
	if (k == 1) return 1;
	if (k % 2 == 0)
		return 1ll * (power(p, k / 2) + 1) * sum(p, k / 2) % MOD;
	return (power(p, k - 1)) + sum(p, k - 1) % MOD;
}


void solve() {
	i64 a, b;
	std::cin >> a >> b;

	divide(a);
	i64 res = 1;
	for (auto it : primes) {
		i64 p = it.first, k = it.second * b;
		res = 1ll * res * sum(p, k + 1) % MOD;
	}
	if (!a) res = 0;

	std::cout << res << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
