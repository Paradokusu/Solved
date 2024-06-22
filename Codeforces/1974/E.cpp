#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int M = 50 + 7;
constexpr i64 inf = std::numeric_limits<i64>::max();

int T, n, x, sum;
int a[M], b[M];
i64 f[M][N];

void solve() {
	scanf("%d %d", &n, &x);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		sum += b[i];
	}
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			f[i][j] = -inf;
	f[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++)
			f[i][j] = std::max(f[i - 1][j] + x, f[i][j]);
		for (int j = b[i]; j <= sum; j++) {
			if (f[i - 1][j - b[i]] >= a[i])
				f[i][j] = std::max(f[i][j], f[i - 1][j - b[i]] - a[i] + x);
		}
	}
	
	for (int i = sum; i >= 0; i--) {
		if (f[n][i] >= 0) {
			printf("%d\n", i);
			return;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
