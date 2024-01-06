#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;

int n, m;
int fa[N];

struct edge {
	int u, v, w;
	friend bool operator < (const edge &a, const edge &b) {
		return a.w < b.w;
	}
} e[N];

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

int cnt, ans;

void Kruskal() {
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u);
		int v = find(e[i].v);
		if (u == v) continue;
		ans += e[i].w;
		fa[v] = u;
		cnt++;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	Kruskal();
	if (cnt == n - 1) printf("%d\n", ans);
	else printf("orz\n");
	return 0;
}
