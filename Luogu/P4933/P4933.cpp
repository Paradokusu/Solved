#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;
constexpr int V = 2e4 + 7;
constexpr int MOD = 998244353;

int n, ans;
int a[N], f[N][V * 2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j < i; j++) {
			(f[i][a[i] - a[j] + V] += f[j][a[i] - a[j] + V] + 1) %= MOD;
			(ans += f[j][a[i] - a[j] + V] + 1) %= MOD;
		}
	}
	printf("%d\n", (ans + n) % MOD);
	return 0;
}
