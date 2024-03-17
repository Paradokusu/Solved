#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, m;
int top, cnt, idx;
int dfn[N], low[N], st[N], deg[N];

vector<int> vdcc[N];

int tot = 1, head[N], nxt[N << 1], to[N << 1];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}

void dfs(int u, int lst) {
	low[u] = dfn[u] = ++cnt;
	st[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		if (i != (lst ^ 1)) {
			int v = to[i], fv;
			
			if (!dfn[v]) {
				dfs(v, i);
				low[u] = min(low[u], low[v]);
				
				if (low[v] >= dfn[u]) {
					++idx;
					vdcc[idx].push_back(u);
					++deg[u];	// 增加所属连通分量数量
					// 不同于变种 Tarjan，这里记录的是点所以要加入深度最浅的点
					
					do {
						fv = st[top--];
						vdcc[idx].push_back(fv);
						// 将连通块中边代表的点加入，并在栈中删除掉这条边
						++deg[fv];
					} while (fv != v);
				}
			} else {
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int b, e;
		scanf("%d %d", &b, &e);
		addedge(b, e);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			// 深度最浅的点不会代表任何边，不会被删去，所以要清空栈
			dfs(i, -1);
			top = 0;
		}
	}
	
	int ans = 0;
	// 找出度数 > 1 的点
	for (int i = 1; i <= n; i++) {
		ans += deg[i] > 1;
	}
	
	printf("%d\n", ans);
	for (int i = 1, lst = 0; i <= n; i++) {
		if (deg[i] > 1) {
			if (lst) printf(" ");
			lst = 1;
			printf("%d", i);
		}
	}
	
	printf("\n");
	/* 这段语句是输出每个点连通分量所对应的点
	for (int i = 1; i <= idx; i++) {
		printf("%d :", i);
		for (int j = 0; j < vdcc[i].size(); j++)
			printf(" %d", vdcc[i][j]);
		printf("\n");
	} */
	
	return 0;
}
