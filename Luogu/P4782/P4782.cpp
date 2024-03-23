#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e6 + 7;

int tot, head[N], nxt[N], to[N];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int top, cnt, idx;
int dfn[N], low[N], st[N], bel[N];
bool ins[N];

void dfs(int u) {
	low[u] = dfn[u] = ++cnt;
	ins[st[++top] = u] = 1;
	
	for (int i = head[u]; i; i = nxt[i]) {
		if (!dfn[to[i]]) {
			dfs(to[i]);
			low[u] = min(low[u], low[to[i]]);
		} else if (ins[to[i]]) {
			low[u] = min(low[u], dfn[to[i]]);
		}
	}
	
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		
		do {
			ins[v = st[top--]] = 0;
			bel[v] = idx;
		} while (v != u);
	}
}

int n, m;
int pt[N][2];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, t = 0; i <= n; i++) {
		pt[i][0] = ++t;
		pt[i][1] = ++t;
	}
	
	for (int i = 1; i <= m; i++) {
		int x, a, y, b;
		scanf("%d %d %d %d", &x, &a, &y, &b);
		// 加入 !a 推导出 b，!b 推导出 a 两个命题
		// 且它们互为逆命题
		addedge(pt[x][!a], pt[y][b]);
		addedge(pt[y][!b], pt[x][a]);
	}
	
	for (int i = 1; i <= (n << 1); i++) {
		if (!dfn[i])
			dfs(i);
	}
	
	for (int i = 1; i <= n; i++) {
		if (bel[pt[i][0]] == bel[pt[i][1]]) {
			// 如果 a 当且仅当 !a，无解
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	
	printf("POSSIBLE\n");
	for (int i = 1; i <= n; i++) {
		// 取强连通分量编号小的是一组合法的解
		int d = (bel[pt[i][0]] < bel[pt[i][1]] ? 0 : 1);
		printf("%d%c", d, " \n" [i == n]);
	}
	
	return 0;
}