#include <bits/stdc++.h>

#define inline inline __attribute__((always_inline))

using namespace std;
constexpr int N = 1e5 + 5;

int n, m, d, ans, dis[N];
vector<int> G[N];

inline void add(const int u, const int v) { G[u].push_back(v), G[v].push_back(u); }

void dfs(int u, int fa) {
	if (dis[u] <= d) ans++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 1, u, v; i <= n - 1; i++) { scanf("%d %d", &u, &v); add(u, v); }
	dfs(1, 0);
	printf("%d\n", ans - 1);
	return 0;
}
