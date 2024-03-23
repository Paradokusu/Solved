#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;
constexpr int inf = 2147483647;

int n, m, q;
int idx, cnt, tp;
int low[N], stc[N];
int w[N << 1], dfn[N << 1];
int idf[N << 1], fa[N << 1], siz[N << 1];
int dep[N << 1], son[N << 1], top[N << 1];

std::vector<int> G[N], T[N << 1];
std::multiset<int> S[N << 1];

void tarjan(int u) {
	low[u] = dfn[u] = ++idx;
	stc[++tp] = u;
	for (int v : G[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				++cnt;
				for (int x = 0; x != v; --tp) {
					x = stc[tp];
					T[cnt].push_back(x);
					T[x].push_back(cnt);
				}
				T[cnt].push_back(u);
				T[u].push_back(cnt);
			}
		} else
			low[u] = std::min(low[u], dfn[v]);
	}
}

void dfs1(int u, int lst) {
	fa[u] = lst, dep[u] = dep[lst] + 1, siz[u] = 1;
	for (int v : T[u])
		if (v != lst) {
			dfs1(v, u);
			siz[u] += siz[v];
			if (siz[son[u]] < siz[v]) son[u] = v;
		}
}

void dfs2(int u, int lst, int tp) {
	dfn[u] = ++idx, idf[idx] = u, top[u] = tp;
	if (son[u]) dfs2(son[u], u, tp);
	for (int v : T[u])
		if (v != lst && v != son[u])
			dfs2(v, u, v);
}

#define lo (o << 1)
#define ro (o << 1 | 1)
#define mid ((l + r) >> 1)
#define ls lo, l, mid
#define rs ro, mid + 1, r

int dat[N << 4];

void build(int o, int l, int r) {
	if (l == r) { dat[o] = w[idf[l]]; return ; }
	build(ls), build(rs);
	dat[o] = std::min(dat[lo], dat[ro]);
}

void update(int o, int l, int r, int p, int x) {
	if (l == r) { dat[o] = x; return ; }
	if (p <= mid) update(ls, p, x);
	else update(rs, p, x);
	dat[o] = std::min(dat[lo], dat[ro]);
}

int query(int o, int l, int r, int x, int y) {
	if (r < x || y < l) return inf;
	if (x <= l && r <= y) return dat[o];
	return std::min(query(ls, x, y), query(rs, x, y));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
		std::cin >> w[i];
	cnt = n;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	tarjan(1);
	dfs1(1, 0);
	idx = 0;
	dfs2(1, 0, 1);
	
	for (int i = 1; i <= n; ++i)
		if (fa[i])
			S[fa[i]].insert(w[i]);
	for (int i = n + 1; i <= cnt; ++i)
		w[i] = *S[i].begin();
	build(1, 1, cnt);
	while (q--) {
		char c[5];
		int x, y;
		std::cin >> c >> x >> y;
		if (*c == 'C') {
			update(1, 1, cnt, dfn[x], y);
			if (fa[x]) {
				int u = fa[x];
				S[u].erase(S[u].lower_bound(w[x]));
				S[u].insert(y);
				if (w[u] != *S[u].begin()) {
					w[u] = *S[u].begin();
					update(1, 1, cnt, dfn[u], w[u]);
				}
			}
			w[x] = y;
		} else {
			int ans = inf;
			while (top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]])
					std::swap(x, y);
				ans = std::min(ans, query(1, 1, cnt, dfn[top[x]], dfn[x]));
				x = fa[top[x]];
			}
			if (dfn[x] > dfn[y]) std::swap(x, y);
			ans = std::min(ans, query(1, 1, cnt, dfn[x], dfn[y]));
			if (x > n) ans = std::min(ans, w[fa[x]]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
