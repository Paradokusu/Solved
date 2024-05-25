#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, d[N];
double ans = 0;

int tot, head[N];
struct edge {
	int nxt, to;
} e[N << 1];

void addedge(int x, int y) {
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

void dfs(int x, int dep) {
	d[x] = dep;
	for (int i = head[x]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (d[v] == 0)
			dfs(v, dep + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	
	dfs(1, 1);
	
	for (int i = 1; i <= n; i++)
		ans += 1.0 / d[i];
	printf("%.20lf\n", ans);
	return 0;
}
