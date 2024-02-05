#include <bits/stdc++.h>

using namespace std;

constexpr int N = 6e3 + 7;

int n;
int r[N], dp[N][2];
vector<int> g[N];

void dfs(int u, int fa) {
	dp[u][0] = 0;
	dp[u][1] = r[u];
	
	for (auto v : g[u]) {
		if (v != fa) {
			dfs(v, u);
			dp[u][0] += max(dp[v][0], dp[v][1]);
			dp[u][1] += dp[v][0];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	
	dfs(1, 0);
	
	printf("%d\n", max(dp[1][0], dp[1][1]));
	return 0;
}
