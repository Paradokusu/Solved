#include <bits/stdc++.h>

constexpr int N = 5e5 + 7;
constexpr auto inf = std::numeric_limits<int>::max();

struct node {
	int l, r, len;
	
	void init(int _l, int _r) {
		l = _l;
		r = _r;
		len = _r - _l;
	}
	
	friend bool operator < (const node &a, const node &b) {
		return a.len < b.len;
	}
} a[N];

int n, m, tot;
int ans = inf;
int uni[N << 1];

struct seg {
	int tmax[N << 3], tag[N << 3];
	
	void add(int o, int val) {
		tag[o] += val;
		tmax[o] += val;
	}
	
	void pushup(int o) {
		tmax[o] = std::max(tmax[o << 1], tmax[o << 1 | 1]);
	}
	
	void pushdown(int o) {
		if (tag[o]) {
			add(o << 1, tag[o]);
			add(o << 1 | 1, tag[o]);
			tag[o] = 0;
		}
	}
	
	void build(int o, int l, int r) {
		tag[o] = tmax[o] = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(o << 1, l, mid);
		build(o << 1 | 1, mid + 1, r);
	}
	
	void update(int o, int l, int r, int x, int y, int val) {
		if (x > r || y < l) return;
		if (x <= l && y >= r) {
			add(o, val);
			return;
		}
		
		pushdown(o);
		int mid = (l + r) >> 1;
		if (x <= mid)
			update(o << 1, l, mid, x, y, val);
		if (y > mid)
			update(o << 1 | 1, mid + 1, r, x, y, val);
		pushup(o);
	}
	
	int query() {
		return tmax[1];
	}
} tr;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		a[i].init(l, r);
		uni[++tot] = l;
		uni[++tot] = r;
	}
	
	std::sort(a + 1, a + n + 1);
	std::sort(uni + 1, uni + tot + 1);
	tot = std::unique(uni + 1, uni + tot + 1) - uni - 1;
	for (int i = 1; i <= n; i++) {
		a[i].l = std::lower_bound(uni + 1, uni + tot + 1, a[i].l) - uni;
		a[i].r = std::lower_bound(uni + 1, uni + tot + 1, a[i].r) - uni;
	}
	
	int now = 0;
	tr.build(1, 1, tot);
	for (int i = 1; i <= n; i++) {
		tr.update(1, 1, tot, a[i].l, a[i].r, 1);
		while (tr.query() >= m) {
			ans = std::min(ans, a[i].len - a[now].len);
			tr.update(1, 1, tot, a[now].l, a[now].r, -1);
			now++;
		}
	}
	
	printf("%d\n", (ans == inf) ? -1 : ans);
	return 0;
}
