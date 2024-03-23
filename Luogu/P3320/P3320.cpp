#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n, m;

int tot, head[N], to[N << 1], nxt[N << 1], w[N << 1];
void addedge(int b, int e, int z) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; w[tot] = z;
}

int idx, dfn[N], idf[N];
int dep[N], fa[N][20];
i64 ans, dis[N];
bool vis[N];

set<int> s;

void dfs(int u, int lst) {
	dfn[u] = ++idx;
	idf[idx] = u;
	dep[u] = dep[fa[u][0] = lst] + 1;
	
	for (int j = 1; (1 << j) < dep[u]; j++)
		fa[u][j] = fa[fa[u][j - 1]][j - 1];
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != lst) {
			dis[to[i]] = dis[u] + w[i];
			dfs(to[i], u);
		}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int d = dep[x] - dep[y], j = 0; d; d >>= 1, j++) {
		if (d & 1)
			x = fa[x][j];
	}
	
	if (x == y) return x;
	for (int j = 18; ~j; j--)
		if (fa[x][j] != fa[y][j]) {
			x = fa[x][j];
			y = fa[y][j];
		}
	
	return fa[x][0];
}

i64 lgth(int x, int y) {
	return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	
	dfs(1, 0);
	
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d", &x);
		x = dfn[x];
		if (!vis[idf[x]])
			s.insert(x);

		set<int>::iterator it;
		y = idf[(it = s.lower_bound(x)) == s.begin() ? *--s.end() : *--it];
		z = idf[(it = s.upper_bound(x)) == s.end() ? *s.begin() : *it];
		if (vis[idf[x]])
			s.erase(x);

		x = idf[x];
		i64 d = lgth(x, y) + lgth(x, z) - lgth(y, z);
		if (!vis[x]) {
			vis[x] = 1;
			ans += d;
		} else {
			vis[x] = 0;
			ans -= d;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
