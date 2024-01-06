#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 7;
constexpr int inf = 1e9;

int n, tot, now;
int nxt[N], go[N], head[N];
int seg[N], son[N], fa[N];
int siz[N], rev[N], ans[N], s[N], dep[N], num[N], cnt[1 << 23];

void add(int x, int y, int z) {
	nxt[++tot] = head[x];
	head[x] = tot, go[tot] = y, s[tot] = z;
}

void clear(int x) {
	for (int i = seg[x]; i <= seg[x] + siz[x] - 1; i++)
		cnt[num[rev[i]]] = -inf;
}

void add1(int x) {
	ans[now] = max(ans[now], dep[x] + cnt[num[x]]);
	for (int i = 0; i <= 21; i++)
		ans[now] = max(ans[now], dep[x] + cnt[(1 << i) ^ num[x]]);
}

void add2(int x) {
	cnt[num[x]] = max(cnt[num[x]], dep[x]);
}

void dfs1(int x) {
	dep[x] = dep[fa[x]] + 1, siz[x] = 1;
	seg[x] = ++seg[0], rev[seg[x]] = x;
	for (int i = head[x], y; i, y = go[i]; i = nxt[i]) {
		num[y] = num[x] ^ (1 << s[i]);
		dfs1(y);
		siz[x] += siz[y];
		if (siz[y] > siz[son[x]])
			son[x] = y;
	}
}

void dfs2(int x, int flg) {
	for (int i = head[x], y; i, y = go[i]; i = nxt[i]) {
		if (y == son[x]) continue;
		dfs2(y, 0);
	}
	if (son[x])
		dfs2(son[x], 1);
	now = x;
	for (int i = head[x], y; i, y = go[i]; i = nxt[i]) {
		if (y == son[x]) continue;
		for (int i = seg[y]; i <= seg[y] + siz[y] - 1; i++)
			add1(rev[i]);
		for (int i = seg[y]; i <= seg[y] + siz[y] - 1; i++)
			add2(rev[i]);
	}
	add1(x), add2(x);
	ans[x] -= (dep[x] << 1);
	for (int i = head[x], y; i, y = go[i]; i = nxt[i])
		ans[x] = max(ans[x], ans[y]);
	if (!flg) clear(x);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (1 << 22); i++)
		cnt[i] = -inf;
	for (int i = 2, x; i <= n; i++) {
		char ch;
		scanf("%d %c", &x, &ch);
		fa[i] = x;
		add(x, i, ch - 'a');
	}
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", max(ans[i], 0));
	printf("\n");
	return 0;
}
