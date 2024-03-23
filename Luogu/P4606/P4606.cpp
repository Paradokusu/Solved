#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int T, n, m, q, cnt;
int t0t, top, num;
int dfn[N << 1], low[N], stc[N], w[N << 1];
int dep[N << 1], dis[N << 1], fa[N << 1][20];
vector<int> G[N], F[N << 1];

void init() {
	for (int i = 1; i <= n; i++) {
		G[i].clear();
		dfn[i] = low[i] = 0;
	}
	
	for (int i = 1; i <= (n << 1); i++) {
		F[i].clear();
	}
}

void tarjan(int u) {
	low[u] = dfn[u] = ++t0t;
	stc[++top] = u;
	
	for (auto v : G[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				++cnt;
				for (int x = 0; x != v; top--) {
					x = stc[top];
					F[cnt].push_back(x);
					F[x].push_back(cnt);
				}
				F[cnt].push_back(u);
				F[u].push_back(cnt);
			}
		} else
			low[u] = min(low[u], dfn[v]);
	}
}

void dfs(int u, int lst) {
	dfn[u] = ++t0t;
	dep[u] = dep[fa[u][0] = lst] + 1;
	dis[u] = dis[lst] + (u <= n);
	for (int j = 0; j <= 18; j++)
		fa[u][j + 1] = fa[fa[u][j]][j];
	for (int v : F[u])
		if (v != lst)
			dfs(v, u);
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = 0, d = dep[x] - dep[y]; d; d >>= 1, j++) {
		if (d & 1)
			x = fa[x][j];
	}
	if (x == y) return x;
	for (int j = 18; ~j; j--) {
		if (fa[x][j] != fa[y][j]) {
			x = fa[x][j];
			y = fa[y][j];
		}
	}
	return fa[x][0];
}

bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		init();
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		cnt = n;
		
		t0t = 0;
		tarjan(1);
		top--;
		
		t0t = 0;
		dfs(1, 0);
		
		scanf("%d", &q);
		while (q--) {
			static int s, a[N];
			scanf("%d", &s);
			int ans = -2 * s;
			
			for (int i = 1; i <= s; i++)
				scanf("%d", &a[i]);
			sort(a + 1, a + s + 1, cmp);
			for (int i = 1; i <= s; i++) {
				int u = a[i], v = a[i % s + 1];
				ans += dis[u] + dis[v] - 2 * dis[lca(u, v)];
			}
			if (lca(a[1], a[s]) <= n)
				ans += 2;
			printf("%d\n", ans / 2);
		}
	}
	return 0;
}