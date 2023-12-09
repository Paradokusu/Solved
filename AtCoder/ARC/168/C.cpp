#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 2e5 + 5e4 + 5, Mod = 998244353;

int n, k;
i64 ans, cnt[5], fac[N], inv[N];
char s[N];

i64 Cal(i64 m, i64 a) {
	if (m < a) return 0;
	return fac[m] * inv[m - a] % Mod * inv[a] % Mod;
}

i64 qpow(i64 x, int p) {
	i64 res = 1;
	while (p) {
		if (p & 1) res = res * x % Mod;
		x = x * x % Mod, p >>= 1;
	}
	return res;
}

void solve() {
	scanf("%d %d %s", &n, &k, s);
	for (auto c : s) cnt[c - 'A']++;
	for (int i = 0; 2 * i <= k; i++)
		for (int a = 0; a + 2 * i <= k; a++)		// AB
			for (int b = 0; b + 2 * i + a <= k && i + a + b <= cnt[0]; b++)	// AC
				for (int c = 0; a + b + c + 2 * i <= k && i + a + c <= cnt[1] && i + b + c <= cnt[2]; c++) {	// BC
					i64 s = 1, ms = 1;
					s = Cal(cnt[0], i + a + b) % Mod * Cal(i + a + b, i + a) % Mod * Cal(cnt[2], i + b + c) % Mod * Cal(i + b + c, i + b) % Mod * Cal(cnt[1], i + a + c) % Mod * Cal(i + a + c, i + c) % Mod;
					ms *= Cal(cnt[0], i + a + b) % Mod * Cal(i + a + b, i + b) % Mod * Cal(cnt[2], i + b + c) % Mod * Cal(i + b + c, i + c) % Mod * Cal(cnt[1], i + a + c) % Mod * Cal(i + a + c, i + a) % Mod;
					ans = (ans + ms + (i == 0 ? 0 : 1) * s) % Mod;
				}
	printf("%lld\n", ans);
}

int main() {
	fac[0] = 1, n = 250000;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % Mod;
	inv[n] = qpow(fac[n], Mod - 2);
	for (int i = n - 1; ~i; i--)
		inv[i] = inv[i + 1] * (i + 1) % Mod;
	solve();
	return 0;
}
