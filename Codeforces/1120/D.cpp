#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 7;

int n, id, cot;
i64 ans;
int a[N], deg[N], fa[N], dfn[N];
vector<int> t, g[N];

struct edge {
	int u, v, w, id;
} e[N];

bool cmp(const edge &a, const edge &b) {
	return a.w < b.w;
}

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void dfs(int u, int fa) {
	dfn[u] = cot + 1;
	if (u != 1 && deg[u] == 1) cot++;
	for (auto v : g[u])
		if (v != fa)
			dfs(v, u);
	e[++id] = {dfn[u], cot + 1, a[u], u};
}

void Kruskal() {
	sort(e + 1, e + n + 1, cmp);
	for (int i = 1; i <= cot + 1; i++)
		fa[i] = i;

	for (int i = 1, j; i <= n; i = j) {
		j = i;
		while (j != n + 1 && e[j].w == e[i].w) {
			int fu = find(e[j].u), fv = find(e[j].v);
			if (fu != fv) t.emplace_back(e[j].id);
			j++;
		}
		for (int k = i; k <= j - 1; k++) {
			int fu = find(e[k].u), fv = find(e[k].v);
			if (fu != fv) fa[fu] = fv, ans += e[k].w;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		++deg[u], ++deg[v];
	}
	
	dfs(1, 1);
	Kruskal();

	printf("%lld %d\n", ans, t.size());
	sort(t.begin(), t.end());
	for (auto i : t)
		printf("%d ", i);
	printf("\n");
	return 0;
}
