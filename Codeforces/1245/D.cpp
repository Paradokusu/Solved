#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pil = pair<int, i64>;
using plii = pair<i64, pair<int, int>>;

constexpr int N = 2007;

int n, cnt, cot;
i64 tot, x[N], y[N], c[N], k[N], dis[N];
bool vis[N], flg[N];

vector<pil> g[N];
priority_queue<plii, vector<plii>, greater<plii>> q;

struct edge {
	int u, v;
	i64 w;
} ans[N];

void Prim(int x) {
	q.push({0, {x, 0}});
	for (int i = 0; i <= n; i++)
		dis[i] = 1e18;
	dis[x] = 0;
	
	while (!q.empty()) {
		plii it = q.top();
		q.pop();
		int u = it.second.first;
		if (vis[u])
			continue;
		++cnt, tot += dis[u], vis[u] = 1;
		ans[cnt] = {it.second.second, it.second.first, dis[u]};
		if (it.second.second == 0)
			flg[u] = 1, ++cot;
		if (cnt >= n + 1) return;
		for (auto i : g[u]) {
			int v = i.first;
			i64 w = i.second;
			if (dis[v] > w) {
				dis[v] = w;
				q.push({dis[v], {v, u}});
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
		g[0].push_back({i, c[i]});
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
		for (int j = 1; j < i; j++) {
			i64 d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			d = d * (k[i] + k[j]);
			g[i].push_back({j, d});
			g[j].push_back({i, d});
		}
	}
	
	Prim(0);
	
	printf("%lld\n%d\n", tot, cot - 1);
	for (int i = 1; i <= n; i++)
		if (flg[i])
			printf("%d ", i);
	printf("\n");
	int res = 0;
	for (int i = 1; i <= cnt; i++) {
		if (ans[i].u != 0 && ans[i].v != 0)
			++res;
	}
	printf("%d\n", res);
	for (int i = 1; i <= cnt; i++) {
		if (ans[i].u != 0 && ans[i].v != 0)
			printf("%d %d\n", ans[i].u, ans[i].v);
	}
	return 0;
}
