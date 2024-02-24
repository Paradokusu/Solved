#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1024 + 7;

int n, k, cnt;
i64 sta[N], sit[N], dp[20][N][105];
/*
* sta: 有几个国王
* sit: 国王的放置情况——1 表示放、2 表示不妨
*/

void dfs(int x, int num, int cur) {
	if (cur >= n) {		// 状态合法
		sit[++cnt] = x;
		sta[cnt] = num;
		return;
	}

	dfs(x, num, cur + 1);	// cur 位置不放国王
	dfs(x + (1 << cur), num + 1, cur + 2);	// cur 位置放国王，相邻位置不能放
}

bool compatible(int j, int x) {
	if (sit[j] & sit[x]) return 0;
	if ((sit[j] << 1) & sit[x]) return 0;
	if (sit[j] & (sit[x] << 1)) return 0;
	return 1;
}

int main() {
	scanf("%d %d", &n, &k);
	dfs(0, 0, 0);	// 预处理一行的所有合法状态

	for (int j = 1; j <= cnt; j++)
		dp[1][j][sta[j]] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= cnt; j++)
			for (int x = 1; x <= cnt; x++) {
				if (!compatible(j, x)) continue;

				for (int l = sta[j]; l <= k; l++)
					dp[i][j][l] += dp[i - 1][x][l - sta[j]];
			}

	i64 ans = 0;

	for (int i = 1; i <= cnt; i++)
		ans += dp[n][i][k];

	printf("%lld\n", ans);
	return 0;
}
