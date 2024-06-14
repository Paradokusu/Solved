#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 7;
constexpr i64 MOD = 1e9 + 7;

int n, m;
i64 k, dis[N];
bool vis[N];

struct edge {
	i64 v, w;
};
std::vector<edge> G[N];

struct trie {
	int t0t, ch[N << 4][2];
	
	void clear() {
		for (int i = 0; i <= t0t; i++)
			ch[i][0] = ch[i][1] = 0;
		t0t = 1;
	}
	
	void insert(int x) {
		int u = 1;
		for (int i = 30; i >= 0; i--) {
			int v = (x >> i) & 1;
			if (!ch[u][v])
				ch[u][v] = ++t0t;
			u = ch[u][v];
		}
	}
	
	int query(int u, int s, int pos) {
		if (s > k) return 0;
		if (pos < 0) return 1;
		if (ch[u][0] && ch[u][1])
			return (query(ch[u][0], s + (1ll << pos), pos - 1) + query(ch[u][1], s + (1ll << pos), pos - 1)) % MOD;
		
		int v = ch[u][0] | ch[u][1];
		if (s + (1ll << pos) - 1 <= k)
			return (query(v, s + (1ll << pos), pos - 1) + (1ll << pos)) % MOD;
		return query(v, s, pos - 1);
	}
} tr;

void dfs(int u) {
	vis[u] = 1;
	tr.insert(dis[u]);
	
	for (auto e : G[u]) {
		i64 v = e.v, w = e.w;
		if (vis[v] && (dis[v] != (dis[u] ^ w))) {
			printf("0\n");
			exit(0);
		}
		if (vis[v]) continue;
		dis[v] = dis[u] ^ w;
		dfs(v);
	}
}

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		i64 x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		G[x].push_back({y, z});
		G[y].push_back({x, z});
	}
	
	i64 ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tr.clear();
			dfs(i);
			ans = (ans * tr.query(1, 0, 30)) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
