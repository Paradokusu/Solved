#include <bits/stdc++.h>

constexpr int N = 207;

int n, m, idx;
int fir[N], lst[N];
int dx[N << 1], nxt[N << 1];
long long ans, dp[1 << 20][20];

void Build(int x, int y) {
	dx[++idx] = y;

	if (!fir[x])
		fir[x] = idx;
	else
		nxt[lst[x]] = idx;

	lst[x] = idx;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		Build(x, y);
		Build(y, x);
	}

	for (int i = 0; i < n; i++)
		dp[1 << i][i] = 1;

	for (int k = 1; k < (1 << n); k++) {
		for (int i = 0; i < n; i++) {
			if (!dp[k][i])	// 状态不存在
				continue;

			for (int j = fir[i]; j; j = nxt[j]) {
				int y = dx[j];	// 直接`枚举相邻边

				if ((k & (-k)) > (1 << y))	// 不合法
					continue;

				if (k & (1 << y)) {
					if ((k & (-k)) == (1 << y))	// 第一个经过的点
						ans += dp[k][i];
				} else
					dp[k | (1 << y)][y] += dp[k][i];	// 第一个经过，直接转移
			}
		}
	}

	std::cout << 1ll * (ans - m) / 2 << "\n";
	return 0;
}
