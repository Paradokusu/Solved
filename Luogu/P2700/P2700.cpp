#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n, k;
i64 ans, p[N], fa[N];
bool vis[N];

struct edge {
	int u, v, w;
} g[N];

bool cmp(const edge& x, const edge& y) {
	return x.w > y.w;
}

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (!vis[fx] || !vis[fy]) {
		fa[fx] = fy;
		if (vis[fy]) vis[fx] = 1;
		else if (vis[fx]) vis[fy] = 1;
		return 1;
	}
	return 0;
}

void Kruskal() {
	sort(g + 1, g + n, cmp);
	for (int i = 1; i < n; i++) {
		edge e = g[i];
		int u = e.u, v = e.v;
		if (merge(u, v))
			ans -= e.w;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1, in; i <= k; i++) {
		scanf("%d", &in);
		vis[in] = 1;
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
		ans += g[i].w;
	}
	Kruskal();
	printf("%lld\n", ans);
	return 0;
}
