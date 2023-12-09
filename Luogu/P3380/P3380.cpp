#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5, Inf = 2147483647;

struct seg {
	int v, ls, rs;
} t[N * 128];

int n, m, tot, cnt, num, len;
int a[N], rt[N], tem[N], tmp[N], lsh[N << 1];

struct qs {
	int a, b, c, d;
} q[N];

int lowbit(int x) { return x & (-x); }

void pushup(const int o) { t[o].v = t[t[o].ls].v + t[t[o].rs].v; }

void change(int &o, int l, int r, int k, int v) {
	if (!o) o = ++tot;
	if (l == r) { t[o].v += v; return; }
	int mid = (l + r) >> 1;
	if (k <= mid) change(t[o].ls, l, mid, k, v);
	else change(t[o].rs, mid + 1, r, k, v);
	pushup(o);
}

int query_num(int l, int r, int k) {
	if (l == r) { return l; }
	int mid = (l + r) >> 1, sum = 0;
	for (int i = 1; i <= cnt; i++) sum += t[t[tem[i]].ls].v;
	for (int i = 1; i <= num; i++) sum -= t[t[tmp[i]].ls].v;
	// 统计左子树个数
	if (k <= sum) {
		for (int i = 1; i <= cnt; i++) tem[i] = t[tem[i]].ls;
		for (int i = 1; i <= num; i++) tmp[i] = t[tmp[i]].ls;
		return query_num(l, mid, k);	// 进入左子树，所有节点进入左子树
	} else {
		for (int i = 1; i <= cnt; i++) tem[i] = t[tem[i]].rs;
		for (int i = 1; i <= num; i++) tmp[i] = t[tmp[i]].rs;
		return query_num(mid + 1, r, k - sum);	// 进入右子树，所有节点进入右子树
	}
}

int query_rnk(int l, int r, int k) {
	if (l == r) { return 0; }
	int mid = (l + r) >> 1, sum = 0;
	// 统计左子树个数
	if (k <= mid) {
		for (int i = 1; i <= cnt; i++) tem[i] = t[tem[i]].ls;
		for (int i = 1; i <= num; i++) tmp[i] = t[tmp[i]].ls;
		return query_rnk(l, mid, k);	// 进入左子树，所有节点进入左子树
	} else {
		for (int i = 1; i <= cnt; i++) sum += t[t[tem[i]].ls].v, tem[i] = t[tem[i]].rs;
		for (int i = 1; i <= num; i++) sum -= t[t[tmp[i]].ls].v, tmp[i] = t[tmp[i]].rs;
		return sum + query_rnk(mid + 1, r, k);	// 进入右子树，所有节点进入右子树
	}
}

void add(int o, int v) {
	for (int i = o; i <= n; i += lowbit(i)) change(rt[i], 1, len, a[o], v);
}

int find_num(int l, int r, int k) {
	cnt = num = 0;
	for (int i = r; i; i -= lowbit(i)) tem[++cnt] = rt[i];
	for (int i = l - 1; i; i -= lowbit(i)) tmp[++num] = rt[i];	// 存储前 l - 1 棵树的合并在树状数组上的表示
	return query_num(1, len, k);
}

int find_rnk(int l, int r, int k) {
	cnt = num = 0;
	for (int i = r; i; i -= lowbit(i)) tem[++cnt] = rt[i];
	for (int i = l - 1; i; i -= lowbit(i)) tmp[++num] = rt[i];
	return query_rnk(1, len, k) + 1;
}

int find_pri(int l, int r, int k) {
	int rk = find_rnk(l, r, k) - 1;
	if (rk == 0) return 0;	// 特判如果其已经是最小数的情况
	return find_num(l, r, rk);
}

int find_nxt(int l, int r, int k) {
	if (k == len) return len + 1;	// 特判输入已经达到数据范围上限的情况
	int rk = find_rnk(l, r, k + 1);	// 查询 k + 1 的排名，查到的即为 1 ~ k 中的数的个数 + 1
	if (rk == r - l + 2) return len + 1;	// 特判已经是最大数的情况
	return find_num(l, r, rk);
}

int main() {
	scanf("%d %d", &n, &m);
	tot = cnt = num = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		lsh[++len] = a[i];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &q[i].a, &q[i].b, &q[i].c);
		if (q[i].a != 3) scanf("%d", &q[i].d);
		else lsh[++len] = q[i].c;
		if (q[i].a == 4 || q[i].a == 5) lsh[++len] = q[i].d;
	}
	sort(lsh + 1, lsh + len + 1);
	len = unique(lsh + 1, lsh + len + 1) - lsh - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(lsh + 1, lsh + len + 1, a[i]) - lsh;
		add(i, 1);
	}
	lsh[0] = -Inf, lsh[len + 1] = Inf;
	for (int i = 1; i <= m; i++) {
		if (q[i].a == 3) {
			add(q[i].b, -1);
			a[q[i].b] = lower_bound(lsh + 1, lsh + len + 1, q[i].c) - lsh;
			add(q[i].b, 1);
		} else if (q[i].a == 1) {
			q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
			printf("%d\n", find_rnk(q[i].b, q[i].c, q[i].d));
		} else if (q[i].a == 2) {
			printf("%d\n", lsh[find_num(q[i].b, q[i].c, q[i].d)]);
		} else if (q[i].a == 4) {
			q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
			printf("%d\n", lsh[find_pri(q[i].b, q[i].c, q[i].d)]);
		} else if (q[i].a == 5) {
			q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
			printf("%d\n", lsh[find_nxt(q[i].b, q[i].c, q[i].d)]);
		}
	}
	return 0;
}