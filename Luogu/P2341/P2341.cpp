#include <bits/stdc++.h>

constexpr int N = 1e4 + 7;
constexpr int M = 5e4 + 7;

int head[N], nxt[M], to[M], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int n, m;
int col, t0t, top;
int dfn[N], low[N], stc[N];
int co[N], de[N], di[N], si[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++t0t;
	stc[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else {
			if (!co[v])
				low[u] = std::min(low[u], dfn[v]);
		}
	}
	
	if (low[u] == dfn[u]) {
		co[u] = ++col;
		++si[col];
		
		while (stc[top] != u) {
			++si[col];
			co[stc[top]] = col;
			top--;
		}
		
		top--;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		addedge(v, u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			tarjan(i);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = nxt[j])
			if (co[i] != co[to[j]])
				de[co[to[j]]]++;
	}
	
	int ans = 0, u = 0;
	for (int i = 1; i <= col; i++)
		if (!de[i]) {
			ans = si[i];
			u++;
		}
	
	if (u == 1)
		std::cout << ans << "\n";
	else
		std::cout << "0\n";
	
	return 0;
}
