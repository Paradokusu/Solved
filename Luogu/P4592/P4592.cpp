#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;
constexpr int S = 6e6 + 5 + 2e5;
constexpr int C = 29;

int n, q, tot, a[N];
int h[N], to[N << 1], nxt[N << 1];

void Add(int u, int v) {
	nxt[++tot] = h[u], to[tot] = v, h[u] = tot;
	nxt[++tot] = h[v], to[tot] = u, h[v] = tot;
}

int sz[S], trie[S][2], cnt;
int rt1[N], rt2[N];

void Ins(int &o, int x, int p) {
	trie[++cnt][0] = trie[o][0], trie[cnt][1] = trie[o][1], sz[cnt] = sz[o], o = cnt;
	++sz[o];
	if (~p) Ins(trie[o][x >> p & 1], x, p - 1);
}

int ldf[N], rdf[N], dep[N], faz[N][20], dfc;

void DFS(int u, int fa) {
	ldf[u] = ++dfc, faz[u][0] = fa, dep[u] = dep[fa] + 1;
	Ins(rt1[dfc] = rt1[dfc - 1], a[u], C);
	Ins(rt2[u] = rt2[fa], a[u], C);
	for (int j = 1; (1 << j) < dep[u]; j++) faz[u][j] = faz[faz[u][j - 1]][j - 1];
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fa) DFS(to[i], u);
	rdf[u] = dfc;
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) x ^= y ^= x ^= y;
	for (int d = dep[x] - dep[y], j = 0; d; d >>= 1, ++j) if (d & 1) x = faz[x][j];
	if (x == y) return x;
	for (int j = 16; ~j; j--) if (faz[x][j] != faz[y][j]) x = faz[x][j], y = faz[y][j];
	return faz[x][0];
}

int Qur(int o1, int o2, int x, int j) {
	if (j == -1) return 0;
	int p = (x >> j & 1) ^ 1;
	if (sz[trie[o1][p]] - sz[trie[o2][p]]) return Qur(trie[o1][p], trie[o2][p], x, j - 1) | 1 << j;
	return Qur(trie[o1][p ^ 1], trie[o2][p ^ 1], x, j - 1);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, u, v; i < n; i++) { scanf("%d %d", &u, &v); Add(u, v); }
	DFS(1, 0);
	for (int i = 1, opt, x, y, z; i <= q; i++) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d %d", &x, &z);
			printf("%d\n", Qur(rt1[rdf[x]], rt1[ldf[x] - 1], z, C));
		} else {
			scanf("%d %d %d", &x, &y, &z);
			int w = faz[LCA(x, y)][0];
			printf("%d\n", max(Qur(rt2[x], rt2[w], z, C), Qur(rt2[y], rt2[w], z, C)));
		}
	}
	return 0;
}