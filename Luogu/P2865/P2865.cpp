#include <bits/stdc++.h>

constexpr int inf = 2147483647;

struct edge {
	int to, val;
};

struct node {
	int pos, dis;

	friend bool operator < (const node &a, const node &b) {
		return a.dis > b.dis;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<edge> g[n + 1];
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	std::vector<std::vector<int>> dis(2, std::vector<int>(n + 1));
	std::function<void()> Dijkstra2 = [&]() {
		std::priority_queue<node> q;
		for (int i = 1; i <= n; i++) {
			dis[0][i] = dis[1][i] = inf;
		}

		dis[0][1] = 0;
		node t;
		t.dis = 0, t.pos = 1;
		q.push(t);

		while (!q.empty()) {
			t = q.top();
			q.pop();
			int u = t.pos, d = t.dis;
			if (d > dis[1][u]) {
				continue;
			}

			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].to;
				int w = g[u][i].val;
				if (dis[0][v] > d + w) {
					dis[1][v] = dis[0][v];
					t.dis = dis[0][v] = d + w;
					t.pos = v;
					q.push(t);
				}
				if (dis[1][v] > d + w && dis[0][v] < d + w) {
					t.dis = dis[1][v] = d + w;
					t.pos = v;
					q.push(t);
				}
			}
		}
	};
	Dijkstra2();

	std::cout << dis[1][n] << "\n";
	return 0;
}
