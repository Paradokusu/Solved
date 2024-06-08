#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1.5e3 + 7;
constexpr int S = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

int n, m, K;
int ps[N], pre[N];
int fac[S], inv[S];
int f[N][N];

void reduce(int &x) { x += x >> 31 & MOD; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int expow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}
void fma(int &x, int y, int z) { x = (1ll * y * z + x) % MOD; }
int C(int a, int b) { return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD; }

int main() {
	fac[0] = fac[1] = 1;
	inv[0] = inv[1] = 1;
	for (int i = 2; i < S; i++) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[MOD % i], MOD - MOD / i);
	}
	for (int i = 2; i < S; i++)
		inv[i] = mul(inv[i - 1], inv[i]);
	
	scanf("%d %d", &n, &m);
	int a, b;
	scanf("%d %d", &a, &b);
	int P = expow(b, MOD - 2, a);
	scanf("%d", &K);
	for (int i = 0; i <= m && i <= K; i++)
		ps[i] = expow(P, i, expow(1 + MOD - P, K - i, C(K, i)));
	for (int i = 0; i <= m; i++)
		reduce(pre[i] = ps[i] + (i ? pre[i - 1] - MOD : 0));
	f[0][m] = 1;
	for (int i = 1; i <= n; i++) {
		static int tp[N], ts[N];
		for (int j = 1; j <= m; j++) {
			reduce(tp[j] = tp[j - 1] + f[i - 1][j] - MOD);
			fma(ts[j] = ts[j - 1], ps[j], tp[j]);
		}
		for (int r = 1; r <= m; r++) {
			int sm = mul(pre[r - 1], tp[m] - tp[m - r] + MOD);
			reduce(sm -= ts[r - 1]);
			f[i][r] = mul(ps[m - r], sm);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= m; i++)
		reduce(ans += f[n][i] - MOD);
	printf("%d\n", ans);
	return 0;
}

