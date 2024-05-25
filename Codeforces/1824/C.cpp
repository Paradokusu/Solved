#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, ans, a[N];
vector<int> g[N];
map<int, int> f[N];

void dfs(int x, int fa) {
	if (fa && g[x].size() == 1)
		return f[x][a[x]] = 1, void();
	int mx = 1, cnt = 0;
	for (int y : g[x]) {
		if (y != fa) {
			a[y] ^= a[x];
			dfs(y, x);
			cnt++;
			if (f[x].size() < f[y].size())
				swap(f[x], f[y]);
			for (auto [v, k] : f[y])
				mx = max(mx, f[x][v] += k);
		}
	}
	ans += cnt - mx;
	map<int, int> t;
	if (mx > 1) {
		for (auto i : f[x])
			if (i.second == mx)
				t[i.first] = 1;
		swap(f[x], t);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	printf("%d\n", ans + (!f[1][0]));
	return 0;
}
