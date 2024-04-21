#include <bits/stdc++.h>

constexpr int N = 107;
constexpr int M = 10;

int n, m, cot;
int line[N], sr[(1 << M) + 7], sum[(1 << M) + 7];;
int dp[N][(1 << M) + 7][(1 << M) + 7];
char S[N];

void dfs(int lst, int stat, int num) {
	if (stat >= m) {
		sum[++cot] = num;
		sr[cot] = lst;
		return;
	}
	
	dfs(lst, stat + 1, num);
	dfs(lst | (1 << stat), stat + 3, num + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	dfs(0, 0, 0);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> S;
		
		for (size_t k = 0; k < strlen(S); k++)
			if (S[k] == 'H')
				line[i] |= (1 << k);
	}
	
	for (int i = 1; i <= cot; i++) {
		if (sr[i] & line[1])
			continue;

		for (int j = 1; j <= cot; j++)
			dp[1][sr[i]][sr[j]] = sum[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= cot; j++) {
			for (int k = 1; k <= cot; k++) {
				for (int l = 1; l <= cot; l++) {
					if ((sr[j] & sr[k]) || (sr[j] & sr[l]) || (sr[k] & sr[l]))
						continue;
					
					if ((sr[j] & line[i]) || (sr[k] & line[i - 1]) || (sr[l] & line[i - 2]))
						continue;
					
					dp[i][sr[j]][sr[k]] = std::max(dp[i][sr[j]][sr[k]], dp[i - 1][sr[k]][sr[l]] + sum[j]);
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= cot; i++)
		for (int j = 1; j <= cot; j++)
			ans = std::max(ans, dp[n][sr[i]][sr[j]]);

	std::cout << ans << "\n";
	return 0;
}
