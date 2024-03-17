#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

vector<int> G[N], Gi[N];

bitset<N> vis;
int top, ans, stc[N];

void dfs1(int u) {	// 获取 dfs 生成树
	vis[u] = 1;
	for (auto i : G[u])
		if (!vis[i])
			dfs1(i);
	stc[++top] = u;
}

int siz[N], bel[N];

void dfs2(int u, int id) {	// 在反图上 dfs 获取强连通分量
	vis[u] = 1;
	bel[u] = id;
	siz[id]++;
	for (auto i : Gi[u])
		if (!vis[i])
			dfs2(i, id);
}

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int b, e;
		scanf("%d %d", &b, &e);
		G[b].push_back(e);
		Gi[e].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs1(i);
	}

	vis.reset();
	int idx = 0;

	while (top) {
		int u = stc[top--];
		if (!vis[u])
			dfs2(u, ++idx);
	}

	for (int i = 1; i <= idx; i++)
		ans += (siz[i] > 1);

	printf("%d\n", ans);
	return 0;
}
