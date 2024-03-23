#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;

int tot, head[N], nxt[N << 1], to[N << 1];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int n, m;
int top, idx, t0t;
int dfn[N], low[N], stc[N], siz[N];

i64 ans[N];
vector<int> g[N];

void pb(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void tarjan(int u, int lst) {
	dfn[u] = low[u] = ++t0t;
	stc[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++idx;
				pb(u, idx);
				
				int d;
				do {
					d = stc[top--];
					pb(d, idx);
				} while (d != v);
			}
		} else if (v != lst)
			low[u] = min(low[u], dfn[v]);
	}
}

void dfs(int u, int fa) {
	for (auto i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		ans[u] += 2ll * siz[v] * siz[u];
		siz[u] += siz[v];
	}
	
	siz[u] += u <= n;
	ans[u] += 2ll * (siz[u] - 1) * (n - siz[u]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	
	idx = n;
	tarjan(1, 0);
	dfs(1, 0);
	
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i] + 2 * (n - 1));
	}
	
	return 0;
}
