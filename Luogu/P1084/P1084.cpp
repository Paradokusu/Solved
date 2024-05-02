#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 7;

int n, m;
int f[N][20], am[N];
i64 dis[N][20];

struct node {
	int id;
	i64 rest;
} a[N], b[N];

int vis[N], usd[N], rsb[N];
i64 rsm[N];

struct edge {
	int v, w;
};

std::vector<edge> g[N << 1];

bool cmp(const node &x, const node &y) {
	return x.rest > y.rest;
}

int tot, h[N], nxt[N << 1], to[N << 1];
i64 w[N << 1];

void addedge(int x, int y, int z) {
	to[++tot] = y;
	nxt[tot] = h[x];
	h[x] = tot;
	w[tot] = z;
}

void dfs(int u, int lst, i64 hg) {
	f[u][0] = lst;
	dis[u][0] = hg;
	
	for (int i = 1; i <= 17; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
		dis[u][i] = dis[u][i - 1] + dis[f[u][i - 1]][i - 1];
	}
	
	for (int i = h[u]; i != -1; i = nxt[i]) {
		int v = to[i];
		
		if (v != lst)
			dfs(v, u, w[i]);
	}
}

int na, nb;

int run(int u, int lst) {
	int bs = 1, bs0 = 0;
	
	if (vis[u])
		return 1;
	
	for (int i = h[u]; i != -1; i = nxt[i]) {
		int v = to[i];
		if (v == lst)
			continue;
		
		bs0 = 1;
		
		if (!run(v, u)) {
			bs = 0;
			
			if (u == 1) {
				b[++nb].id = v;
				b[nb].rest = w[i];
			} else
				return 0;
		}
	}
	
	if (!bs0)
		return 0;
	
	return bs;
}

int check(i64 lim) {
	i64 num;
	na = nb = 0;
	
	for (int i = 1; i <= n; i++)
		vis[i] = rsb[i] = 0;
	
	for (int i = 1; i <= m; i++)
		usd[i] = 0;
	
	for (int i = 1; i <= m; i++) {
		int x = am[i];
		num = 0;
		
		for (int j = 17; j >= 0; j--) {
			if (f[x][j] > 1 && num + dis[x][j] <= lim) {
				num += dis[x][j];
				x = f[x][j];
			}
		}
		
		if (f[x][0] == 1 && num + dis[x][0] <= lim) {
			a[++na].rest = lim - num - dis[x][0];
			a[na].id = i;
			
			if (!rsb[x] || a[na].rest < rsm[x]) {
				rsm[x] = a[na].rest;
				rsb[x] = i;
			}
		} else
			vis[x] = 1;
	}
	
	if (run(1, 0))
		return 1;
	
	std::sort(a + 1, a + na + 1, cmp);
	std::sort(b + 1, b + nb + 1, cmp);
	
	int now = 1;
	usd[0] = 1;
	
	for (int i = 1; i <= nb; i++) {
		if (!usd[rsb[b[i].id]]) {
			usd[rsb[b[i].id]] = 1;
			continue;
		}
		
		while (now <= na && (usd[a[now].id] || a[now].rest < b[i].rest))
			++now;
		
		if (now > na)
			return 0;
		
		usd[a[now].id] = 1;
	}
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	
	for (int i = 1; i < n; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	
	dfs(1, 0, 0);
	
	std::cin >> m;
	
	for (int i = 1; i <= m; i++)
		std::cin >> am[i];
	
	i64 l = 0, r = N - 7;

	i64 ans = -1;
	
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}