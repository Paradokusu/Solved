#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int head[N], nxt[N << 1], to[N << 1], tot = 1;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}

int n, m;
pair<int, int> edge[N];

// st 表示用来提取连通块的栈
// bel 表示每个点所属的连通块
int dfn[N], low[N], st[N], bel[N];
int top, cnt, idx, anscnt;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first == y.first)
		return x.second < y.second;
	return x.first < y.first;
}

void dfs(int u, int lst) {
	low[u] = dfn[u] = ++cnt;
	st[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		if (i != (lst ^ 1)) {
			int v = to[i];
			// 防止走重复的边
			if (!dfn[v]) {
				dfs(v, i);
				// 当边是 dfs 树上时，直接取子树 min
				low[u] = min(low[u], low[v]);
				// 发现割边
				if (low[v] > dfn[u])
					edge[anscnt++] = {min(u, v), max(u, v)};
			} else {
				// 当边不是 dfs 树上时，更新到达的深度最低的点
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
	
	// 当子树没有非树边能到达自己祖先的时候
	// 自己就是连通块深度最低的点
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		do {
			v = st[top--];
			bel[v] = idx;	// 将栈顶的一段点标记为同一个边双连通分量
		} while (v != u);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		addedge(a, b);
	}
	
	// 对于原图每个连通块都求解一次边双连通分量
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			dfs(i, -1);
	}
	
	sort(edge, edge + anscnt, cmp);	// 对答案按边排序
	for (int i = 0; i < anscnt; i++) {
		int a = edge[i].first;
		int b = edge[i].second;
		printf("%d %d\n", a, b);
	}
	
	return 0;
}
