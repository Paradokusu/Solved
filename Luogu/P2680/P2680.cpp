#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3e5 + 5;

int n, m, cnt, maxm, maxx;
int dep[N], dis[N], tag[N], t[N], d[N], tu[N], tv[N], fa[N][20];
vector<pair<int, int>> g[N];

void dfs(int x, int p, int d) {
	fa[x][0] = p;
	dep[x] = dep[p] + 1;
	dis[x] = d;
	
	for (size_t i = 0; i < g[x].size(); i++) {
		if (g[x][i].first != p) {
			dfs(g[x][i].first, x, d + g[x][i].second);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 18; ~i; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = 18; ~i; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

void dfsc(int x) {
	for (size_t i = 0; i < g[x].size(); i++) {
		if (g[x][i].first != fa[x][0]) {
			dfsc(g[x][i].first);
			tag[x] += tag[g[x][i].first];
		}
	}
	if (tag[x] == cnt) maxx = max(maxx, dis[x] - dis[fa[x][0]]);
}

bool check(int x) {
	memset(tag, 0, sizeof(tag));
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (d[i] > x) {
			tag[tu[i]]++;
			tag[tv[i]]++;
			tag[t[i]] -= 2;
			cnt++;
		}
	}
	maxx = 0;
	dfsc(1);
	for (int i = 1; i <= m; i++) {
		if (d[i] - maxx > x)
			return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		maxm = max(maxm, w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= 18; i++) {
		for (int j = 1; j <= n; j++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &tu[i], &tv[i]);
		t[i] = lca(tu[i], tv[i]);
		d[i] = dis[tu[i]] + dis[tv[i]] - 2 * dis[t[i]];
		maxx = max(maxx, d[i]);
	}
	
	int l = maxx - maxm, r = maxx, mid, ans = 0;
	while (l <= r) {
		if (check(mid = (l + r) / 2))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	} 
	printf("%d\n", ans);
	return 0;
}
