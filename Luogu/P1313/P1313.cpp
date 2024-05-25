#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e4 + 7;
constexpr int MOD = 10007;

int a, b, k, n, m;
i64 an = 1, bm = 1;
i64 f[N][N];

int main() {
	scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0 || j == i) f[i][j] = 1;
			else f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	for (int i = 1; i <= n; i++)
		an = (an * a) % MOD;
	for (int i = 1; i <= m; i++)
		bm = (bm * b) % MOD;
	printf("%lld\n", (f[k][n] * an * bm) % MOD);
	return 0;
}
