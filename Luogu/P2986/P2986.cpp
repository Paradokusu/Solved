#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr i64 inf = LLONG_MAX;

struct edge {
	int v, w;
};

int n, m;
i64 cnt, ans = inf;
i64 c[N], f[N], d[N], siz[N];

vector<edge> g[N];

void dfs(int u, int fa) {
	siz[u] = c[u];
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		f[u] = f[u] + f[v] + siz[v] * g[u][i].w;
	}
}

void dp(int u, int fa) {
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		if (v == fa) continue;
		d[v] = d[u] - siz[v] * g[u][i].w + (cnt - siz[v]) * g[u][i].w;
		ans = min(ans, d[v]);
		dp(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		cnt += c[i];
	}
	for (int j = 1; j < n; j++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dfs(1, 0);
	d[1] = f[1];
	ans = min(ans, d[1]);
	dp(1, 0);

	printf("%lld\n", ans);
	return 0;
}
