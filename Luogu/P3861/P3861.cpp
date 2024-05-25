#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr int D = 6720 + 7;
constexpr int MOD = 998244353;

int T, tot, pos;
int pos1[N], pos2[N], f[D][D];
i64 n, sqn, tmp;
i64 x[N];

void solve() {
	scanf("%lld", &n);
	tot = 0, sqn = 1ll * sqrt(n);
	for (i64 i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			x[++tot] = i;
			if (i * i != n) x[++tot] = n / i;
		}
	}
	
	sort(x + 1, x + tot + 1);
	for (int i = 1; i * 2 <= tot + 1; i++) {
		pos1[x[i]] = i;
		pos2[x[i]] = tot - i + 1;
	}
	
	for (int i = 1; i <= tot; i++) {
		f[i][1] = (i == 1 ? 1 : 0);
		for (int j = 2; j <= tot; j++) {
			f[i][j] = f[i][j - 1];
			if (j > i) continue;
			if (x[i] % x[j] == 0) {
				tmp = x[i] / x[j];
				pos = (tmp <= sqn ? pos1[tmp] : pos2[n / tmp]);
				f[i][j] = (f[i][j] + f[pos][j - 1]) % MOD;
			}
		}
	}
	
	printf("%d\n", f[tot][tot] - 1);	// 去掉 1 * n 的情况
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
