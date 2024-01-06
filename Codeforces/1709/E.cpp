#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int n, ans;
int a[N], d[N], f[N];

set<int> st[N];
vector<int> g[N];

void dfs1(int x, int fa) {
	f[x] = fa, d[x] = d[fa] ^ a[x];
	for (size_t i = 0; i < g[x].size(); i++) {
		int to = g[x][i];
		if (to == fa) continue;
		dfs1(to, x);
	}
}

void dfs2(int x) {
	st[x].insert(d[x]);
	bool flg = 0;
	for (size_t i = 0; i < g[x].size(); i++) {
		int to = g[x][i];
		if (to == f[x]) continue;
		dfs2(to);
		if (st[x].size() < st[to].size()) swap(st[x], st[to]);
		for (auto i : st[to]) {
			if (st[x].find(i ^ a[x]) != st[x].end())
				flg = 1;
		}
		for (auto i : st[to])
			st[x].insert(i);
	}
	if (flg) {
		ans += 1;
		st[x].clear();
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs1(1, 0);
	dfs2(1);
	printf("%d\n", ans);
	return 0;
}
