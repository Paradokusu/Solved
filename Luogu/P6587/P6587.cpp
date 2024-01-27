#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;
constexpr int M = (1 << 20) + 7;

int n, m, rt, cot, a[N];
i64 lst;

struct SegmentTree {
	int ls, rs, len;
	i64 val, tag;
} tr[M << 1];

void Pushup(int o) {
	tr[o].val = tr[tr[o].ls].val + tr[tr[o].rs].val;
}

void Pushdown(int o) {
	i64 tg = tr[o].tag;
	tr[o].tag = 0;
	tr[tr[o].ls].val += tg * tr[tr[o].ls].len;
	tr[tr[o].rs].val += tg * tr[tr[o].rs].len;
	tr[tr[o].ls].tag += tg;
	tr[tr[o].rs].tag += tg;
}

void Build(int &o, int l, int r, int x, int dep) {
	o = ++cot;
	tr[o].tag = 0;
	
	if (l == r) {
		if (x && (x <= n)) {
			tr[o].val = a[x];
			tr[o].len = 1;
		} else {
			tr[o].val = tr[o].len = 0;
		}
		return;
	}
	
	int mid = (l + r) >> 1;
	Build(tr[o].ls, l, mid, x, dep + 1);
	Build(tr[o].rs, mid + 1, r, x | (1 << dep), dep + 1); 
	tr[o].len = tr[tr[o].ls].len + tr[tr[o].rs].len;
	
	Pushup(o);
}

void Modify(int o, int l, int r, int p, int v, int x, int dep) {
	if (dep == p) {
		tr[o].val += 1ll * v * tr[o].len;
		tr[o].tag += v;
		return;
	}
	
	if (tr[o].tag)
		Pushdown(o);
	
	int mid = (l + r) >> 1;
	if (!(x & (1 << dep)))
		Modify(tr[o].ls, l, mid, p, v, x, dep + 1);
	else
		Modify(tr[o].rs, mid + 1, r, p, v, x, dep + 1);
	
	Pushup(o);
}

i64 Query(int o, int l, int r, int p, int x, int dep) {
	if (dep == p)
		return tr[o].val;
	if (tr[o].tag)
		Pushdown(o);
	
	int mid = (l + r) >> 1;
	i64 ans = 0;
	
	if (!(x & (1 << dep)))
		ans = Query(tr[o].ls, l, mid, p, x, dep + 1);
	else
		ans = Query(tr[o].rs, mid + 1, r, p, x, dep + 1);

	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	Build(rt, 0, (1 << 20) - 1, 0, 0);
	
	for (int i = 1; i <= m; i++) {
		int opt, x, y;
		scanf("%d %d %d", &opt, &x, &y);
		opt = (lst + opt) % 2 + 1;
		
		if (opt == 1) {
			int in;
			scanf("%d", &in);
			Modify(rt, 0, (1 << 20) - 1, x, in, y, 0);
		} else {
			lst = Query(rt, 0, (1 << 20) - 1, x, y, 0);
			printf("%lld\n", lst);
		}
	}
	
	return 0;
}

