#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;
constexpr int M = 6e5 + 7;

int t0t, lst[N];
struct edge {
	int x, y, pre;
} a[N << 1];

void Addedge(int x, int y) {
	a[++t0t] = {x, y, lst[x]};
	lst[x] = t0t;
}

int n, m;
int idx, cnt, top;
int dfn[N], low[N], deg[N];
int c[N], siz[N], stc[N];
bool v[N];

std::map<int, std::map<int, bool>> h;

void dfs(int x) {
	dfn[x] = low[x] = ++idx;
	stc[++top] = x;
	v[x] = 1;
	
	for (int i = lst[x]; i; i = a[i].pre) {
		int y = a[i].y;
		
		if (!dfn[y]) {
			dfs(y);
			low[x] = std::min(low[x], low[y]);
		} else if (v[y])
			low[x] = std::min(low[x], dfn[y]);
	}
	
	if (low[x] == dfn[x]) {
		int y;
		cnt++;
		
		do {
			y = stc[top--];
			v[y] = 0;
			c[y] = cnt;
			siz[cnt]++;
		} while (x != y);
	}
}

void Tarjan() {
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs(i);
	
	int t = t0t;
	t0t = 0;
	memset(lst, 0, sizeof(lst));
	
	for (int i = 1; i <= t; i++) {
		int x = a[i].x, y = a[i].y;
		
		if (c[x] != c[y] && !h[c[x]][c[y]]) {
			Addedge(c[x], c[y]);
			h[c[x]][c[y]] = h[c[y]][c[x]] = 1;
			deg[c[y]]++;
		}
	}
}

bool Check(int x) {
	if (deg[x] || siz[x] > 1)
		return 0;
	
	for (int i = lst[x]; i; i = a[i].pre) {
		int y = a[i].y;
		
		if (deg[y] == 1)
			return 0;
	}
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		Addedge(x, y);
	}
	
	Tarjan();
	
	int tot = 0;
	
	for (int i = 1; i <= cnt; i++)
		tot += !deg[i];
	
	for (int i = 1; i <= cnt; i++) {
		if (Check(i)) {
			tot--;
			break;
		}
	}
	
	std::cout << std::fixed << std::setprecision(6) << 1.0 * (n - tot) / n << "\n";
	return 0;
}
