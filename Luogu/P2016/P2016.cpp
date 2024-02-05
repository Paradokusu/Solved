#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1507;

int n;
int dp[N][2];
vector<int> g[N];

void dfs(int u, int fa) {
	dp[u][1] = 1;
	dp[u][0] = 0;
	
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1], dp[v][0]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, k;
		scanf("%d %d", &x, &y);
		for (int j = 1; j <= y; j++) {
			scanf("%d", &k);
			g[x].emplace_back(k);
			g[k].emplace_back(x);
		}
	}
	
	dfs(0, -1);
	
	printf("%d\n", min(dp[0][0], dp[0][1]));
	return 0;
}
