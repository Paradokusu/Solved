#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int tot, head[N], nxt[N], to[N];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int n, m, cnt, idx, top;
int dfn[N], low[N], stc[N], siz[N], bel[N];
bitset<N> ins;

void dfs(int u) {
	low[u] = dfn[u] = ++cnt;
	ins[stc[++top] = u] = 1;	// 标记为在栈中

	for (int i = head[u]; i; i = nxt[i]) {
		if (!dfn[to[i]]) {	// 进入未标记的点
			dfs(to[i]);
			low[u] = min(low[u], low[to[i]]);
		} else if (ins[to[i]]) {
			// 这种写法包含了前向边和返祖边两种情况
			// 于是 low 的 DP 意义被淡化，成为辅助合并的标记
			// 前向边重点在栈中，则 dfn[to[i]] 一定比 dfn[u] 大，不会影响
			low[u] = min(low[u], dfn[to[i]]);
		}
	}

	if (low[u] == dfn[u]) {
		int v;
		++idx;

		do {
			v = stc[top--];
			bel[v] = idx;
			ins[v] = 0;	// 弹出栈的时候维护在栈中的信息
			++siz[idx];	// 统计大小
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

	// 一次 dfs 不一定能跑完全部点，所以跑多次 dfs
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			dfs(i);
	}

	int ans = 0;
	for (int i = 1; i <= idx; i++) {
		ans += siz[i] > 1;
	}

	printf("%d\n", ans);
	return 0;
}
