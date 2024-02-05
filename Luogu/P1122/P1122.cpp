#include <bits/stdc++.h>

using namespace std;

constexpr int N = 16007;
constexpr int inf = 2147483647;

int n, ans = -inf;
int a[N], dp[N];

vector<int> g[N];

void dfs(int u, int fa) {
	dp[u] = a[u];
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != fa) {
			dfs(v, u);
			if (dp[v] > 0)
				dp[u] += dp[v];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}
