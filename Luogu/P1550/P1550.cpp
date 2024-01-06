#include <bits/stdc++.h>

using namespace std;

constexpr int N = 300 + 7;

int n;
int w[N], fa[N], g[N][N];

struct edge {
	int u, v, w;
	const bool operator < (const edge& a) const {
		return w > a.w;
	}
};

priority_queue<edge> q;

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

int kruskal() {
	int ans = 0;
	while (!q.empty()) {
		edge t = q.top();
		if (find(t.u) != find(t.v)) {
			fa[fa[t.v]] = fa[t.u];
			ans += t.w;
		}
		q.pop();
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &g[i][j]);
			if (i != j)
				q.push({i, j, g[i][j]});
		}
	}
	
	n++;
	for (int i = 1; i < n; i++) {
		q.push({i, n, w[i]});
		q.push({n, i, w[i]});
	}
	printf("%d\n", kruskal());
	return 0;
}
