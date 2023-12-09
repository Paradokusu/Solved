#include <bits/stdc++.h>

#define inline inline __attribute__((always_inline))

using namespace std;
constexpr int N = 5e5 + 5;

int n, s, far, ans = N * 1000;
int dis[N], fa[N], flag[N];

struct edge {
	int to, w;
};
vector<edge> G[N];

inline void add(int u, int v, int w) { G[u].push_back({v, w}), G[v].push_back({u, w}); }

void dfs(int u, int f) {
	fa[u] = f;
	if (dis[u] > dis[far]) far = u;	// 记录最远距离
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].to, w = G[u][i].w;
		if (v == f || flag[v]) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);	// 遍历下一个
	}
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1, u, v, w; i <= n - 1; i++) { scanf("%d %d %d", &u, &v, &w); add(u, v, w); }
	int A, B;	// 直径的两端
	dis[1] = 1; dfs(1, 0); A = far;	// 第一次 DFS 找到第一个直径
	dis[far] = 0; dfs(far, 0); B = far;	// 第一次 DFS 找到第二个直径
	for (int i = B, j = B; i; i = fa[i]) {
		while (dis[j] - dis[i] > s)  j = fa[j];	// 双指针
		int x = max(dis[B] - dis[j], dis[i]);	// 两端最远的距离
		ans = min(ans, x);
	}
	for (int i = B; i; i = fa[i]) flag[i] = 1;
	for (int i = B; i; i = fa[i]) { dis[i] = 0, dfs(i, fa[i]); }	// 计算直径上每个点可访问的最远距离
	for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);	// 最大值
	printf("%d\n", ans);
	return 0;
}
