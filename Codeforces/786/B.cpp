#include <bits/stdc++.h>

using i64 = long long;
using pil = std::pair<int, i64>;
using pli = std::pair<i64, int>;

constexpr int N = 1e5 + 7;
constexpr i64 inf = 1e18;

int n, q, s;
int t0t, rt1, rt2;
int pos[N];

i64 dis[N << 3];
std::vector<pil> e[N << 3];
std::bitset<(N << 3)> vis;

struct node {
	int l, r, lson, rson;
};

struct SegTree {
	node tr[N << 3];

	int ls(int o) { return tr[o].lson; }
	int rs(int o) { return tr[o].rson; }

	void build1(int &o, int l, int r) {	// 动态开点——入树
		o = ++t0t;
		tr[o] = node{l, r};
		if (l == r) { pos[l] = o; return; }
		int mid = (l + r) >> 1;
		build1(tr[o].lson, l, mid);
		build1(tr[o].rson, mid + 1, r);
		e[o].emplace_back(ls(o), 0);
		e[o].emplace_back(rs(o), 0);
	}

	void build2(int &o, int l, int r) {	// 动态开点——出树
		if (l == r) { o = pos[l]; return; }
		o = ++t0t;
		tr[o] = node{l, r};
		int mid = (l + r) >> 1;
		build2(tr[o].lson, l, mid);
		build2(tr[o].rson, mid + 1, r);
		e[ls(o)].emplace_back(o, 0);
		e[rs(o)].emplace_back(o, 0);
	}

	void add1(int o, int l, int r, int v, i64 w) {	// 点向区间连边
		if (l <= tr[o].l && tr[o].r <= r) { e[v].emplace_back(o, w); return; }
		int mid = (tr[o].l + tr[o].r) >> 1;
		if (l <= mid) add1(ls(o), l, r, v, w);
		if (r > mid) add1(rs(o), l, r, v, w);
	}

	void add2(int o, int l, int r, int v, i64 w) {  // 区间向点连边
		if (l <= tr[o].l && tr[o].r <= r) { e[o].emplace_back(v, w); return; }
		int mid = (tr[o].l + tr[o].r) >> 1;
		if (l <= mid) add2(ls(o), l, r, v, w);
		if (r > mid) add2(rs(o), l, r, v, w);
	}
} seg;

void dijkstra(int s) {
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>> q;
	int tot = (n << 2);
	for (int i = 1; i <= tot; i++)
		dis[i] = inf;
	dis[s] = 0;
	q.emplace(dis[s], s);
	while (!q.empty()) {
		pli fr = q.top();
		q.pop();
		int u = fr.second;
		if (vis[u]) continue;
		for (pil it : e[u]) {
			int v = it.first;
			i64 w = it.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.emplace(dis[v], v);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> q >> s;
	seg.build1(rt1, 1, n);
	seg.build2(rt2, 1, n);

	while (q--) {
		int op, u, l, r, v;
		i64 w;
		std::cin >> op >> u;
		if (op == 1) {
			std::cin >> v >> w;
			e[pos[u]].emplace_back(pos[v], w);
		} else if (op == 2) {
			std::cin >> l >> r >> w;
			seg.add1(rt1, l, r, pos[u], w);
		} else {
			std::cin >> l >> r >> w;
			seg.add2(rt2, l, r, pos[u], w);
		}
	}

	dijkstra(pos[s]);
	for (int i = 1; i <= n; i++) {
		if (dis[pos[i]] == inf) std::cout << "-1 ";
		else std::cout << dis[pos[i]] << " ";
	}
	std::cout << "\n";
	return 0;
}
