#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, m;
int dp[N << 8], L[N << 8];
int s[N][30], num[30];

bool bin(int s, int x) {
	return (s & (1 << (x - 1)));
}

void dfs(int x, int s, bool p) {
	if (x == m)
		return;
	
	if (p) {
		L[s | (1 << x)] = L[s] + num[x + 1];
		dfs(x + 1, s | (1 << x), 1);
		dfs(x + 1, s | (1 << x), 0);
	} else {
		dfs(x + 1, s, 1);
		dfs(x + 1, s, 0);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j];
		
		s[i][in]++;
		num[in]++;
	}
	
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	
	memset(dp, 0x3f, sizeof(dp));
	
	dp[0] = 0;
	
	for (int i = 1; i < (1 << m); i++) {
		for (int j = 1; j <= m; j++) {
			if (bin(i, j)) {
				int l = L[i ^ (1 << (j - 1))], r = L[i];
				dp[i] = std::min(dp[i], dp[i ^ (1 << (j - 1))] + (r - l) - (s[r][j] - s[l][j]));
			}
		}
	}
	
	std::cout << dp[(1 << m) - 1] << "\n";
	return 0;
}
