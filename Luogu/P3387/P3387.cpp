#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int tot, head[N], nxt[N], to[N];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int n, m;
int cnt, top, idx;
int dfn[N], low[N], stc[N], bel[N];
int ans, dp[N], val[N];
bool ins[N];

void dfs(int u) {
	low[u] = dfn[u] = ++cnt;
	ins[stc[++top] = u] = 1;
	
	for (int i = head[u]; i; i = nxt[i]) {
		if (!dfn[to[i]]) {
			dfs(to[i]);
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]])
			low[u] = std::min(low[u], dfn[to[i]]);
	}
	
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		int sum = 0;
		
		do {
			ins[v = stc[top--]] = 0;
			bel[v] = idx;
			sum += val[v];
			
			// 找到强连通分量的所有出边进行转移
			for (int i = head[v]; i; i = nxt[i])
				dp[idx] = std::max(dp[idx], dp[bel[to[i]]]);
		} while (v != u);
		
		// 路径的值需要加上本身的值
		dp[idx] += sum;
		ans = std::max(ans, dp[idx]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> val[i];
	for (int i = 1; i <= m; i++) {
		int b, e;
		std::cin >> b >> e;
		addedge(b, e);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs(i);
	std::cout << ans << "\n";
	return 0;
}
