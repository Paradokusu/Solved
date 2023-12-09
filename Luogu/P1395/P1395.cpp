#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e4 + 5;
constexpr int Inf = 1e9;

int n, center, sum;
int f[N], h[N], size[N], dep[N];
vector<int> G[N];
queue<int> q;

void Add(int u, int v) { G[u].push_back(v), G[v].push_back(u); }

void Gec(int u, int fa) {
	size[u] = 1, f[u] = 0;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa) continue;
		Gec(v, u);
		size[u] += size[v], f[u] = max(f[u], size[v]);	// f[u] 保存了点 u 的最大子树大小
	}
	f[u] = max(f[u], n - size[u]);
	if (f[u] < f[center] || ((f[u] == f[center]) && u < center)) center = u;
}

void Bfs() {
	q.push(center);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (dep[v] || v == center) continue;
			dep[v] = dep[u] + 1, sum += dep[v];
			q.push(v);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i <= n - 1; i++) { scanf("%d %d", &u, &v); Add(u, v); }
	f[0] = Inf;
	Gec(1, 0);	// 求重心
	Bfs();
	printf("%d %d\n", center, sum);
	return 0;
}
