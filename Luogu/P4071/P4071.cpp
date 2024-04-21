#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr int MOD = 1e9 + 7;

i64 expow(i64 a, i64 b = MOD - 2) {
	i64 res = 1 % MOD;
	
	for (; b; b >>= 1) {
		if (b & 1)
			res = 1ll * res * a % MOD;

		a = 1ll * a * a % MOD;
	}
	
	return res;
}

i64 fac[N], D[N];
void pre() {
	fac[0] = 1;
	D[0] = 1;
	
	for (i64 i = 1; i <= (int) 1e6; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		D[i] = (1ll * D[i - 1] * i + (i % 2 ? MOD - 1 : 1)) % MOD;
	}
}

void solve() {
	i64 n, m;
	std::cin >> n >> m;
	i64 c = 1ll * fac[n] * expow(fac[m]) % MOD * expow(fac[n - m]) % MOD;
	std::cout << 1ll * c * D[n - m] % MOD << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	pre();
	
	while (t--) {
		solve();
	}
	
	return 0;
}
