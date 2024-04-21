#include <bits/stdc++.h>

constexpr int N = 107;
constexpr int M = 2e3 + 7;
constexpr int MOD = 998244353;

int ops, mats;
int a[N][M];
int S[N];
int dp[N][N << 1];

int main() {
	// freopen("meal.in", "r", stdin);
	// freopen("meal.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> ops >> mats;
	int prod = 1;
	
	for (int i = 1; i <= ops; i++) {
		for (int j = 0; j < mats; j++) {
			std::cin >> a[i][j];
			S[i] = (S[i] + a[i][j]) % MOD;	// 前缀和
		}
		
		prod = 1ll * prod * (S[i] + 1) % MOD;	// 统计满足限制 1 2 的方案总数
	}
	
	int ans = (prod + MOD - 1) % MOD;
	
	for (int x = 0; x < mats; x++) {	// 枚举烹饪方法
		memset(dp, 0, sizeof(dp));
		dp[0][0 + 101] = 1;
		int no = 0;
		
		for (int i = 1; i <= ops; i++) {
			int res = (S[i] + MOD - a[i][x]) % MOD;	// 选择其他烹饪方法的方案总数
			
			for (int dt = 1; dt <= 201; dt++) {	// 分类讨论转移
				dp[i][dt + 1] = (dp[i][dt + 1] + 1ll * a[i][x] * dp[i - 1][dt]) % MOD;
				dp[i][dt - 1] = (dp[i][dt - 1] + 1ll * res * dp[i - 1][dt]) % MOD;
				dp[i][dt] = (dp[i][dt] + dp[i - 1][dt]) % MOD;
			}
		}
		
		for (int dt = 1; dt <= ops; dt++)
			no = (no + dp[ops][dt + 101]) % MOD;	// 统计总数违反限制 3 的方案总数
		
		ans = (ans + MOD - no) % MOD;
	}
	
	std::cout << ans << "\n";
}
