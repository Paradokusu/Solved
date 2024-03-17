#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 7;

struct node {
	int tot;
	int head[N], nxt[N << 1], to[N << 1];

	void addedge(int b, int e) {
		nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
		nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
	}
} G, T;

int n, m, top, idx, t0t, t1, t2, sznow;
int dfn[N], low[N], st[N], sz[N], sz2[N];

i64 ans;

void tarjan(int u) {	// 建立圆方树
	sz[u] = -1;
	++sznow;
	dfn[u] = low[u] = ++t0t;
	st[++top] = u;

	for (int i = G.head[u]; i; i = G.nxt[i]) {
		if (!dfn[G.to[i]]) {
			tarjan(G.to[i]);
			low[u] = min(low[u], low[G.to[i]]);
			if (dfn[u] <= low[G.to[i]]) {
				++idx;
				int v;

				do {
					v = st[top--];
					T.addedge(v, idx);
					++sz[idx];
				} while (v != G.to[i]);

				++sz[idx];
				T.addedge(u, idx);
			}
		} else {
			low[u] = min(low[u], dfn[G.to[i]]);
		}
	}
}

void dfs(int u, int lst) {
	sz2[u] = (u <= n);	// 只有圆点才能作为 s 或者 f，而 c 在圆点或者方点都可以
	i64 cnt = 0;

	for (int i = T.head[u]; i; i = T.nxt[i]) {
		if (T.to[i] != lst) {
			dfs(T.to[i], u);
			// 计算子树两两积
			cnt += 1ll * sz2[T.to[i]] * sz2[u];
			sz2[u] += sz2[T.to[i]];
		}
	}

	// 在 dfs 中，有子节点的子树需要计算
	// 这个计算的同时也考虑了 c 和 s 相同的情况
	cnt += 1ll * sz2[u] * (sznow - sz2[u]);

	// 上面的计算算了一半的情况
	cnt <<= 1;

	// 计算对答案的贡献
	ans += 1ll * sz[u] * cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	idx = n;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &t1, &t2);
		G.addedge(t1, t2);
	}

	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			// 对于图的每个连通分量计算，不要忘记清空
			sznow = 0, top = 0;
			tarjan(i);
			dfs(i, 0);
		}
	}

	printf("%lld\n", ans);
	return 0;
}
