#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, m;
int otd[N], deg[N];
double dp[N];

struct edge {
	int v, w;
};

vector<edge> g[N << 1];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		g[t2].push_back({t1, t3});
		++otd[t1], ++deg[t1];
	}
	
	queue<int> q;
	dp[n] = 0;
	q.push(n);
	
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		
		for (size_t i = 0; i < g[t].size(); i++) {
			int v = g[t][i].v, w = g[t][i].w;
			dp[v] += (dp[t] + w) / otd[v];
			--deg[v];
			if (!deg[v])
				q.push(v);
		}
	}
	
	printf("%.2f\n", dp[1]);
	return 0;
}
