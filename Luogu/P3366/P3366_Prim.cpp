#include <bits/stdc++.h>

using namespace std;
constexpr int N = 4e5 + 5;

struct node {
	int pos, dis;
	friend bool operator < (const node &a, const node &b) {
		return a.dis > b.dis;
	}
} t;

struct edge {
	int to, val;
};

int n, m, tot, ans, dis[N];
bool vis[N];
vector<edge> g[N];
priority_queue<node> q;

void Prim() {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	t.dis = 0, t.pos = 1;
	q.push(t);
	while (!q.empty()) {
		t = q.top();
		q.pop();
		int u = t.pos, d = t.dis;
		if (vis[u]) continue;
		tot++, vis[u] = 1, ans += dis[u];
		for (size_t i = 0; i< g[u].size(); i++) {
			int v = g[u][i].to, w = g[u][i].val;
			if (dis[v] > w) {
				t.dis = dis[v] = w;
				t.pos = v;
				q.push(t);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	Prim();
	if (tot == n) printf("%d\n", ans);
	else printf("orz\n");
	return 0;
}
