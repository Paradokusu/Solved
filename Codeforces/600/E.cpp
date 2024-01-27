#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 1e5 + 7;
constexpr i64 A = 1e5; 
constexpr i64 T = 5e6 + 7;

i64 n, cnt;
i64 clr[N << 1], rt[N << 1], ans[N << 1];

struct SegmentTree {
	i64 l, r, sum, val, ans;
} tr[T];

std::vector<i64> g[N << 1];

void Pushup(i64 o) {
	if (tr[tr[o].l].sum > tr[tr[o].r].sum) {
		tr[o].sum = tr[tr[o].l].sum;
		tr[o].val = tr[tr[o].l].val;
		tr[o].ans = tr[tr[o].l].ans; 
	}
	
	if (tr[tr[o].l].sum < tr[tr[o].r].sum) {
		tr[o].sum = tr[tr[o].r].sum;
		tr[o].val = tr[tr[o].r].val;
		tr[o].ans = tr[tr[o].r].ans;
	}
	
	if (tr[tr[o].l].sum == tr[tr[o].r].sum) {
		tr[o].sum = tr[tr[o].l].sum;
		tr[o].val = tr[tr[o].r].val;
		tr[o].ans = tr[tr[o].l].ans + tr[tr[o].r].ans;
	}
}

void Update(i64 &o, i64 l, i64 r, i64 pos, i64 v) {
	if (!o) o = ++cnt;
	if (l == r) {
		tr[o].val = l;
		tr[o].sum += v;
		tr[o].ans = l;
		return;
	}
	
	i64 mid = (l + r) >> 1;
	
	if (pos <= mid) Update(tr[o].l, l, mid, pos, v);
	else Update(tr[o].r, mid + 1, r, pos, v);
	
	Pushup(o);
}

i64 Merge(i64 a, i64 b, i64 l, i64 r) {
	if (!a) return b;
	if (!b) return a;
	
	if (l == r) {
		tr[a].val = l;
		tr[a].sum += tr[b].sum;
		tr[a].ans = l;
		
		return a;
	}
	
	i64 mid = (l + r) >> 1;
	tr[a].l = Merge(tr[a].l, tr[b].l, l, mid);
	tr[a].r = Merge(tr[a].r, tr[b].r, mid + 1, r);
	
	Pushup(a);
	
	return a;
}

void dfs(i64 u, i64 fa) {
	for (size_t i = 0; i < g[u].size(); i++) {
		i64 v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		Merge(rt[u], rt[v], 1, A);
	}
	
	Update(rt[u], 1, A, clr[u], 1);
	ans[u] = tr[rt[u]].ans;
}

int main() {
	scanf("%lld", &n);
	
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", &clr[i]);
		rt[i] = i, cnt++;
	}
	
	for (i64 i = 1; i < n; i++) {
		i64 u, v;
		scanf("%lld %lld", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	dfs(1, 0);
	
	for (i64 i = 1; i <= n; i++)
		printf("%lld ", ans[i]);	
	
	printf("\n");
	return 0;
} 

