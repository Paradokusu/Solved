#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e3 + 7;

struct edge {
	int v, w;
};

int n, m;
int v[N], t[N], f[N][N];
vector<edge> g[N];

int dfs(int u = 1) {
	if (u > n - m) {
		f[u][1] = v[u];
		return 1;
	}
	
	int sum = 0;
	for (size_t i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v, cnt = dfs(v);
		sum += cnt;
		for (int j = 1; j <= sum; j++)
			t[j] = f[u][j];
		for (int j = 0; j <= sum; j++)
			for (int k = max(0, j + cnt - sum); k <= min(cnt, j); k++)
				f[u][j] = max(f[u][j], t[j - k] + f[v][k] - g[u][i].w);
	}
	
	return sum;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(f, 0xcf, sizeof(f));
	
	for (int i = 1, k; i <= n - m; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int to, val;
			scanf("%d %d", &to, &val);
			g[i].push_back({to, val});
		}
	}
	
	for (int i = n - m + 1; i <= n; i++)
		scanf("%d", &v[i]);

	dfs();
	
	for (int i = m; i >= 0; i--) {
		if (f[1][i] >= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	
	return 0;
}
