#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;
constexpr int MOD = 10000;

int n, k;
int f[N][N];

int main() {
	scanf("%d %d", &n, &k);
	f[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j <= k; j++) {
			sum = (sum + f[i - 1][j]) % MOD;
			f[i][j] = sum;
			if (j >= i - 1)
				sum = (sum - f[i - 1][j - i + 1] + MOD) % MOD;
		}
	}
	printf("%d\n", f[n][k]);
	return 0;
}

