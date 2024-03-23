#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e5 + 7;

int head1[N], nxt1[N << 1], to1[N << 1], tot1 = 1;
void add1(int b, int e) {
	nxt1[++tot1] = head1[b]; to1[head1[b] = tot1] = e;
}

int head2[N], nxt2[N << 1], to2[N << 1], tot2 = 1;
void add2(int b, int e) {
	nxt2[++tot2] = head2[b]; to2[head2[b] = tot2] = e;
}

int n, m;
int top, idx, tot, ans;
int dfn[N], low[N], stc[N], bel[N], f[N];

void tarjan(int u, int lst) {
	dfn[u] = low[u] = ++tot;
	stc[++top] = u;
	
	for (int i = head1[u]; i; i = nxt1[i]) {
		int v = to1[i];
		if ((i ^ 1) == lst)
			continue;
		if (!dfn[v]) {
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
		} else if (!bel[v])
			low[u] = min(low[u], dfn[v]);
	}
	
	if (low[u] == dfn[u]) {
		int v;
		idx++;
		
		do {
			v = stc[top--];
			bel[v] = idx;
		} while (v != u);
	}
}

void dfs(int u, int fa) {
	for (int i = head2[u]; i; i = nxt2[i]) {
		int v = to2[i];
		if (v == fa)
			continue;
		dfs(v, u);
		ans = max(ans, f[u] + f[v] + 1);
		f[u] = max(f[u], f[v] + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add1(y, x);
		add1(x, y);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			tarjan(i, 0);
	}
	
	for (int u = 1; u <= n; u++) {
		for (int i = head1[u]; i; i = nxt1[i]) {
			int v = to1[i];
			if (bel[v] != bel[u])
				add2(bel[u], bel[v]);
		}
	}
	
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
