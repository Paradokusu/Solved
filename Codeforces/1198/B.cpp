#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int T, n;
int a[N];

struct node {
	int l, r, lzy;
} tr[N << 8];

void pushdown(int o) {
	tr[o << 1].lzy = max(tr[o << 1].lzy, tr[o].lzy);
	tr[o << 1 | 1].lzy = max(tr[o << 1 | 1].lzy, tr[o].lzy);
	tr[o].lzy = 0;
}

void build(int o, int l, int r) {
	tr[o].l = l, tr[o].r = r, tr[o].lzy = 0;
	if (l == r) {
		tr[o].lzy = a[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
}

void update(int x) {
	tr[1].lzy = max(tr[1].lzy, x);
}

void modify(int o, int q, int x) {
	if (tr[o].l == tr[o].r) {
		tr[o].lzy = x;
		return;
	}
	
	pushdown(o);
	int mid = (tr[o].l + tr[o].r) >> 1;
	if (q <= mid)
		modify(o << 1, q, x);
	else
		modify(o << 1 | 1, q, x);
}

int query(int o, int q) {
	if (tr[o].l == tr[o].r) {
		return tr[o].lzy;
	}
	
	pushdown(o);
	int mid = (tr[o].l + tr[o].r) >> 1;
	if (q <= mid)
		return query(o << 1, q);
	else
		return query(o << 1 | 1, q);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	
	scanf("%d", &T);
	while (T--) {
		int op, p, x;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d", &p, &x);
			modify(1, p, x);
		} else {
			scanf("%d", &x);
			update(x);
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d ", query(1, i));
	printf("\n");
	
	return 0;
}
