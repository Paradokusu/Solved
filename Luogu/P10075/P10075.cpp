#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr int M = N << 2;

int n, m, q, k, c[M];
int cnt = 1, head[M], to[M], nxt[M];
bool vis[N];
i64 a[N], d[M];

void add(int x, int y) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int u, int fa = 0) {
	vis[u] = 1;
	for (int i = head[u], v; v = to[i]; a[u] ^= d[i >> 1], i = nxt[i]) {
		if (v != fa) {
			if (vis[v] && !d[i >> 1])
				d[i >> 1] = rand() + 1;
			else if (!vis[v]) {
				dfs(v, u);
				d[i >> 1] = a[v];
			}
		}
	}
}

bool check(int g) {
	i64 pos;
	for (int z = 1; z <= (1 << g) - 1; z++) {
		pos = 0;
		for (int i = 0; i <= g - 1; i++)
			if (z & (1 << i))
				pos ^= d[c[i]];
		if (pos == 0)
			return 0;
	}
	return 1;
}

int main() {
	mt19937_64 rand(time(nullptr));
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	
	dfs(1);
	
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &k);
		for (int i = 0; i <= k - 1; i++)
			scanf("%d", &c[i]);
		if (check(k))
			printf("ymqOAO\n");
		else
			printf("Bob\n");
	}
	
	return 0;
}
