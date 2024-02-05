#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

int n, m;
int sw[N], sv[N], du[N], w[N], v[N], dp[N][507];
int tot, ti, top;
int low[N], dfn[N], stc[N], c[N];

vector<int> e[N], e_[N];

void Tarjan(int x) {
	dfn[x] = low[x] = ++ti;
	stc[++top] = x;
	for (int i = 0, o; i < e[x].size(); i++) {
		o = e[x][i];
		if (!dfn[o]) {
			Tarjan(o);
			low[x] = min(low[x], low[o]);
		} else if (!c[o])
			low[x] = min(low[x], dfn[o]);
	}

	if (dfn[x] == low[x]) {
		++tot;
		while (stc[top + 1] != x) {
			c[stc[top]] = tot;
			sv[tot] += v[stc[top]];
			sw[tot] += w[stc[top]];
			top--;
		}
	}
}

void dfs(int x, int sum) {
	if (sum <= 0) return;
	for (int i = 0, o; i < e_[x].size(); i++) {
		o = e_[x][i];
		for (int j = 0; j <= sum - sw[o]; j++)
			dp[o][j] = dp[x][j];
		dfs(o, sum - sw[o]);
		for (int j = sw[o]; j <= sum; j++)
			dp[x][j] = max(dp[x][j], dp[o][j - sw[o]] + sv[o]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 1, in; i <= n; i++) {
		scanf("%d", &in);
		if (in)
			e[in].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0, u, v; j < e[i].size(); j++) {
			u = c[i], v = c[e[i][j]];
			if (u == v)
				continue;
			du[v]++;
			e_[u].push_back(v);
		}
	}
	for (int i = 1; i <= tot; i++)
		if (!du[i])
			e_[0].push_back(i);

	dfs(0, m);

	printf("%d\n", dp[0][m]);
	return 0;
}
