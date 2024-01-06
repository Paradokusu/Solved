/* 
* 为什么暴力 30 分会 T ？
* 分子 i! 好像不难求？考虑降低分母复杂度。
* zek 说是乘法逆元？
* 和 CF 好像感觉？
* 线筛求质数逆元推合数逆元？
* 记得减掉质因子超过本身大小的情况，会 T。
*/

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e7 + 7;
constexpr i64 mod = 998244353;

i64 n, k, cnt;
i64 inv[N], fac[N], pri[N];

i64 power(i64 a, i64 b) {
	i64 res = 1 % mod;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

int main() {
	scanf("%lld %lld", &n, &k);
	
	inv[1] = 1;
	for (i64 i = 2; i <= n; i++) {
		if (!pri[i]) {
			pri[i] = i;
			fac[++cnt] = i;
			inv[i] = power(power(i, mod - 2), k);
		}
		for (i64 j = 1; fac[j] * i <= n && fac[j] < pri[i]; j++) {
			pri[fac[j] * i] = fac[j];
			inv[fac[j] * i] = inv[fac[j]] * inv[i] % mod;
		}
	}
	
	i64 tot = 1, ans = 0;
	for (i64 i = 1; i <= n; i++) {
		ans = ((ans + tot * inv[i]) % mod) % mod;
		tot = tot * (i + 1) % mod;
	}
	
	printf("%lld\n", ans);
	return 0;
}
