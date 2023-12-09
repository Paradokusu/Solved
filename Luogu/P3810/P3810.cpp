#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

int n, k, tot, cnt;
int ans[N], f[N], root[N << 2], tmp[N << 2];

struct _node {
	int x, y, z, id;
	friend bool operator < (const _node &a, const _node &b) {
		if (a.z == b.z) {
			if (a.y == b.y) return a.x < b.x;
			return a.y < b.y;
		}
		return a.z < b.z;
	}
} node[N];

struct _tree {
	int ls, rs, v;
} t[N * 128];

int lowbit(int x) { return x & (-x); }

void pushup(const int o) { t[o].v = t[t[o].ls].v + t[t[o].rs].v; }

void change(int &o, int l, int r, int w, int v) {
	if (!o) o = ++tot;
	if (l == r) { t[o].v += v; return; }
	int mid = (l + r) >> 1;
	if (w <= mid) change(t[o].ls, l, mid, w, v);
	else change(t[o].rs, mid + 1, r, w, v);
	pushup(o);
}

void add(int o, int w, int v) {
	for (int i = o; i <= k; i += lowbit(i)) change(root[i], 1, k, w, v);
}

int query(int l, int r, int w) {
	if (l == r) {
		int res = 0;
		for (int i = 1; i <= cnt; i++) res += t[tmp[i]].v;
		return res;
	}
	int mid = (l + r) >> 1, sum = 0;
	if (w <= mid) {
		for (int i = 1; i <= cnt; i++) tmp[i] = t[tmp[i]].ls;
		return query(l, mid, w);
	} else {
		for (int i = 1; i <= cnt; i++) sum += t[t[tmp[i]].ls].v, tmp[i] = t[tmp[i]].rs;
		return sum + query(mid + 1, r, w);
	}
}

int find(int r, int w) {
	cnt = 0;
	for (int i = r; i; i -= lowbit(i)) tmp[++cnt] = root[i];
	return query(1, k, w);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) root[i] = ++tot;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &node[i].x, &node[i].y, &node[i].z);
		node[i].id = i;
	}
	sort(node + 1, node + n + 1);
	for (int i = 1; i <= n;) {
		int j = i;
		while (node[j].z == node[j + 1].z)
			add(node[j].x, node[j].y, 1), j++;
		add(node[j].x, node[j].y, 1);
		j = i;
		while (node[j].z == node[j + 1].z)
			f[node[j].id] = find(node[j].x, node[j].y), j++;
		f[node[j].id] = find(node[j].x, node[j].y);
		i = j + 1;
	}
	for (int i = 1; i <= n; i++) ans[f[i]]++;
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
