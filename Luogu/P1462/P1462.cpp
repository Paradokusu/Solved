#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 5;
constexpr int M = 3e5 + 5;
constexpr i64 inf = 1e18;

int n, m, b, l, r, mid;

struct node {
	int a;
	i64 dis;
	
	friend bool operator < (const node &x, const node &y) {
		return x.dis > y.dis;
	}
};
priority_queue<node> q, eq;

int top, g[N], f[N];
i64 dis[N];
bitset<N> vis;

struct edge {
	int adj, nxt;
	i64 w;
} e[M];

void add(int u, int v, i64 w) {
	e[++top] = {v, g[u], w};
	g[u] = top;
}

void Dijkstra(int cost) {
	memset(dis, 0x3f, sizeof(dis));
	vis.reset();
	q = eq;
	dis[1] = 0;
	
	q.push({1, dis[1]});
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		int x = now.a;
		if (vis[x]) continue;
		vis[x] = 1;
		
		for (int i = g[x]; i; i = e[i].nxt) {
			int p = e[i].adj;
			if (f[p] > cost) continue;
			if (dis[x] + e[i].w < dis[p]) {
				dis[p] = dis[x] + e[i].w;
				q.push({p, dis[p]});
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		r = max(r, f[i]);
	}
	l = max(f[1], f[n]);
	
	for (int i = 1; i <= m; i++) {
		int u, v;
		i64 w;
		scanf("%d %d %lld", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	
	while (l < r) {
		mid = (l + r) / 2;
		Dijkstra(mid);
		if (dis[n] > b) l = mid + 1;
		else r = mid;
	}
	Dijkstra(l);
	if (dis[n] > b) printf("AFK\n");
	else printf("%d\n", l);

	return 0;
}