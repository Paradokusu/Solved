#include <bits/stdc++.h>

constexpr int N = 20;
constexpr int MOD = 100'000'000;

int n, m;
int cot, ans;
int g[N][N];
int cow[1 << N], dp[N][1 << N];

void dfs(int stat, int tot) {
	if (tot >= m) {
		cow[++cot] = stat;
		return;
	}
	
	dfs(stat, tot + 1);
	dfs(stat | (1 << tot), tot + 2);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> g[i][j];

	dfs(0, 0);
	
	for (int i = 1; i <= cot; i++) {
		dp[1][cow[i]] = 1;
		
		for (int p = 1; p <= m; p++)
			if (!g[1][p] && (cow[i] & (1 << (p - 1))))
				dp[1][cow[i]] = 0;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= cot; j++) {
			for (int k = 1; k <= cot; k++) {
				// 有相同位意味着有重叠，& 后为 0 表示没有重叠
				if (cow[j] & cow[k])
					continue;

				bool flg = 0;
				
				for (int p = 1; p <= m; p++)
					if (!g[i][p] && (cow[j] & (1 << (p - 1)))) {
						flg = 1;
						break;
					}
				
				if (flg)
					continue;
				
				dp[i][cow[j]] += dp[i - 1][cow[k]];
				dp[i][cow[j]] %= MOD;
			}
		}
	}
	
	for (int i = 1; i <= cot; i++)
		ans = (ans + dp[n][cow[i]]) % MOD;

	std::cout << ans << "\n";
	return 0;
}
