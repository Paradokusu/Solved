#include <bits/stdc++.h>

using namespace std;

constexpr int N = 8e4 + 7;
constexpr int M = 4e5 + 7;

int n, m;
int tot, top, idx;
int head[N], nxt[M], to[M], val[M], coe[M];
int dfn[N], low[N], stc[N], ins[N], bel[N], vt[N], ind[N], dp[N];

void Adde(int b, int e, int v, int c) {
	nxt[++tot] = head[b];
	to[head[b] = tot] = e;
	val[tot] = v;
	coe[tot] = c;
}

void Tarjan(int u) {
	static int t0t;
	dfn[u] = low[u] = ++t0t;
	ins[stc[++top] = u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		if (!dfn[to[i]]) {
			Tarjan(to[i]);
			low[u] = min(low[u], low[to[i]]);
		} else if (ins[to[i]])
			low[u] = min(low[u], dfn[to[i]]);
	}
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		do {
			ins[v = stc[top--]] = false;
			bel[v] = idx;
		} while (v != u);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) {
		double inc;
		scanf("%d %d %d %lf", &u, &v, &w, &inc);
		int _c = round(inc * 10);
		Adde(u, v, w, _c);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i);
	
	static int th[N];
	memcpy(th, head, (n + 1) << 2);
	memset(head, 0, (n + 1) << 2);
	
	for (int u = 1; u <= n; u++) {
		for (int i = th[u]; i; i = nxt[i]) {
			int v = to[i];
			if (bel[u] == bel[v]) {
				int t = val[i];
				while (t) {
					vt[bel[u]] += t;
					t = t * coe[i] / 10;
				}
			} else {
				Adde(bel[v], bel[u], val[i], 0);
				++ind[bel[u]];
			}
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= idx; i++)
		if (!ind[i])
			q.push(i);
	
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		dp[t] += vt[t];
		for (int i = head[t]; i; i = nxt[i]) {
			dp[to[i]] = max(dp[to[i]], dp[t] + val[i]);
			if (!(--ind[to[i]]))
				q.push(to[i]);
		}
	}
	
	int S;
	scanf("%d", &S);
	printf("%d\n", dp[bel[S]]);
	
	return 0;
}
