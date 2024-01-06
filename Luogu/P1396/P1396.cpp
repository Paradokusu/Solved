#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e4 + 7;

int n, m, s, t;
int fa[N];

struct edge {
	int u, v, w;
} g[N];

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void Kruskal() {
	sort(g + 1, g + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = find(g[i].u), y = find(g[i].v);
		if (x != y) fa[x] = y;
		if (find(s) == find(t)) {
			printf("%d\n", g[i].w);
			exit(0);
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
	Kruskal();
	return 0;
}
