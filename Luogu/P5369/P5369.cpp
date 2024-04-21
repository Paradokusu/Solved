#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 20;
constexpr int MOD = 998244353;

i64 n, ans;
i64 dp[(1 << N) + 1], g[(1 << N) + 1], sum[(1 << N) + 1];

i64 lowbit(i64 x) {
	return x & -x;
}

void madd(i64 &a, i64 b) {
	a += b;
	a %= MOD;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (i64 i = 0; i < n; i++)
		std::cin >> sum[1 << i];
	
	for (i64 i = 1; i < (1 << n); i++)
		sum[i] = sum[i & (~(lowbit(i)))] + sum[lowbit(i)];
	
	for (int i = 0; i < n; i++)
		dp[1 << i] = 1;
	
	g[0] = 1;
	
	for (i64 s = 0; s < (1 << n); s++) {
		for (i64 i = 0; i < n; i++) {
			if (s & (1 << i))
				continue;
			
			if (sum[s | (1 << i)] < 0)
				madd(g[s | (1 << i)], g[s]);
			
			if (sum[s] >= 0)
				madd(dp[s | (1 << i)], dp[s]);
		}
	}
	
	for (i64 s = 0; s < (1 << n); s++) {
		madd(ans, sum[s] % MOD * dp[s] % MOD * g[((1 << n) - 1) & (~s)] % MOD);
		ans = (ans % MOD + MOD) % MOD;
	}
	
	std::cout << ans << "\n";
	return 0;
}