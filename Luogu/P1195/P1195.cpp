#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;

int n, m, k, sum, ans;
int fa[N];

struct edge {
	int u, v, w;
} g[N << 4];

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

bool cmp(const edge& x, const edge& y) {
	return x.w < y.w;
}

void Kruskal() {
	sort(g + 1, g + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = find(g[i].u), y = find(g[i].v);
		if (x != y) {
			fa[x] = y;
			sum++, ans += g[i].w;
		}
		if (sum == n - k) {
			printf("%d\n", ans);
			exit(0);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
	Kruskal();
	printf("No Answer\n");
	return 0;
}
