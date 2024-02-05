#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;

int d, t, n, q, a, b, da, db, tot;
int tr[N << 2], dep[N], dfn[N], son[N], siz[N], top[N], fa[N];
vector<int> g[N << 2];

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

void init() {
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		son[i] = 0;
		siz[i] = 0;
	}
	tot = 0;
}

int oDis(int x, int y) {
	int fx = x, fy = y;
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]])
			x = fa[top[x]];
		else
			y = fa[top[y]];
	}
	int lca = 0;
	if (dep[x] < dep[y])
		lca = x;
	else
		lca = y;
	if (lca == fx) return dep[fy] - dep[lca];
	else if (lca == fy) return dep[fx] - dep[lca];
	return dep[fx] + dep[fy] - 2 * dep[lca];
}

void dfs1(int now, int p, int depth) {
	fa[now]= p;
	siz[now] = 1;
	dep[now] = depth;

	int cot = 0;
	for (auto i : g[now]) {
		if (siz[i]) continue;
		dfs1(i, now, depth + 1);
		siz[now] += siz[i];
		if (siz[i] > cot) {
			cot = siz[i];
			son[now] = i;
		}
	}
}

void dfs2(int now, int rt) {
	dfn[now] = ++tot;
	top[now] = rt;
	if (son[now])
		dfs2(son[now], rt);
	for (auto i : g[now])
		if (i != fa[now] && i != son[now])
			dfs2(i, i);
}

int main() {
	d = read<int>(), t = read<int>();
	while (t--) {
		n = read<int>(), q = read<int>();
		init();
		for (int i = 1; i < n; i++) {
			int x = read<int>(), y = read<int>();
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		dfs1(1, 1, 1);
		dfs2(1, 1);
		for (int i = 1; i <= q; i++) {
			a = read<int>(), b = read<int>(), da = read<int>(), db = read<int>();
			int dis = oDis(a, b);
			if (da >= dis)
				puts("Zayin");
			else if (da > db)
				puts("Zayin");
			else if (da < db)
				puts("Ziyin");
			else
				puts("Draw");
		}
	}
	return 0;
}
