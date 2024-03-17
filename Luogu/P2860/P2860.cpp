#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 7;

int n, m;
int top, cnt, idx;

int tot = 1, head[N], nxt[N << 1], to[N << 1];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}

int dfn[N], low[N], st[N], bel[N], deg[N];

void dfs(int u, int lst) {
	low[u] = dfn[u] = ++cnt;
	st[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (i != (lst ^ 1)) {
			if (!dfn[v]) {
				dfs(v, i);
				low[u] = min(low[u], low[v]);
			} else {
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
	
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		do {
			v = st[top--];
			bel[v] = idx;
		} while (v != u);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int b, e;
		scanf("%d %d", &b, &e);
		addedge(b, e);
	}
	
	dfs(1, -1);		// 图联通，只搜索一次
	
	for (int i = 2; i <= tot; i += 2) {
		int u = to[i], v = to[i ^ 1];
		
		// 寻找割边
		if (bel[u] != bel[v]) {
			++deg[bel[u]];
			++deg[bel[v]];
		}
	}
	
	int ans = 0;
	
	// 统计叶子个数
	for (int i = 1; i <= idx; i++)
		ans += (deg[i] == 1);
	
	ans = (ans + 1) / 2;

	printf("%d\n", ans);
	return 0;
}
