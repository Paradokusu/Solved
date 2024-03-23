#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int head[N], to[N], nxt[N], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}

int n, q, r;
int t0t, top, cnt, ans;

int dfn[N], low[N], stc[N], instc[N];
int bel[N], mon[N], sum[N], siz[N], ind[N];

void init() {
	memset(mon, 0x3f, sizeof(mon));
	memset(sum, 0x3f, sizeof(sum));
}

void tarjan(int u) {
	dfn[u] = low[u] = ++t0t;
	instc[u] = 1;
	stc[++top] = u;
	
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else {
			if (instc[v])
				low[u] = std::min(low[u], dfn[v]);
		}
	}
	
	if (dfn[u] == low[u]) {
		cnt++;
		while (stc[top + 1] != u) {
			bel[stc[top]] = cnt;
			instc[stc[top]] = 0;
			siz[cnt]++;
			sum[cnt] = std::min(sum[cnt], mon[stc[top]]);
			top--;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	init();
	std::cin >> n;
	std::cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, t;
		std::cin >> u >> t;
		mon[u] = t;
	}
	std::cin >> r;
	for (int i = 1; i <= r; i++) {
		int u, v;
		std::cin >> u >> v;
		addedge(u, v);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i] && mon[i] != mon[0])
			tarjan(i);
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			std::cout << "NO\n" << i << "\n";
			return 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = nxt[j]) {
			if (bel[i] != bel[to[j]])
				ind[bel[to[j]]]++;
		}
	}
	
	std::cout << "YES\n";
	for (int i = 1; i <= cnt; i++) {
		if (!ind[i])
			ans += sum[i];
	}
	
	std::cout << ans << "\n";
	return 0;
}
