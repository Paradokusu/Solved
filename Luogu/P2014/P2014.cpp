#include <bits/stdc++.h>

using namespace std;

constexpr int N = 307;

int n, m;
int head[N], nxt[N];
int req[N], scr[N], dp[N][N];

void Adde(int x, int y) {
	nxt[y] = head[x];
	head[x] = y;
}

void dfs(int u) {
	memset(dp[u] + 1, 0xc0, m << 2);
	for (int v = head[u]; v; v = nxt[v]) {
		dfs(v);
		static int f[N];
		memset(f, 0xc0, (m + 1) << 2);
		for (int j = 0; j <= m; j++)	
			for (int k = 0; k <= m; k++) {
				f[j + k] = max(f[j + k], dp[u][j] + dp[v][k]);
			}
		memcpy(dp[u], f, (m + 1) << 2);
	}
	if (u == 0) return;
	for (int i = m; i; i--)
		dp[u][i] = dp[u][i - 1] + scr[u];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &req[i], &scr[i]);
		Adde(req[i], i);
	}
	dfs(0);
	printf("%d\n", dp[0][m]);
	return 0;
}
