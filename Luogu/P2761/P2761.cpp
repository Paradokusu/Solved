#include <bits/stdc++.h>

constexpr int N = 107;
constexpr int S = 4e6 + 7;

int n, m, stt;

struct node {
	int b1, b2, f1, f2, t;
} a[N];

std::priority_queue<std::pair<int, int>> q;

int dis[S], hsh[S];

void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));

	dis[stt] = 0;
	q.push({0, stt});
	
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		
		if (hsh[u] == 1)
			continue;
		
		hsh[u] = 1;
		
		for (int i = 1; i <= m; i++) {
			if ((a[i].b1 & u) == a[i].b1 && (a[i].b2 & u) == 0) {
				int v = ((u | a[i].f1) ^ a[i].f1) | a[i].f2;
				
				if (dis[u] + a[i].t < dis[v]) {
					dis[v] = dis[u] + a[i].t;
					q.push({-dis[v], v});
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		stt = stt | (1 << i);
	
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i].t;
		std::string b, f;
		std::cin >> b >> f;
		
		for (int j = 0; j < n; j++) {
			if (b[j] == '+')
				a[i].b1 = a[i].b1 | (1 << (j + 1));
			
			if (b[j] == '-')
				a[i].b2 = a[i].b2 | (1 << (j + 1));
			
			if (f[j] == '+')
				a[i].f2 = a[i].f2 | (1 << (j + 1));
			
			if (f[j] == '-')
				a[i].f1 = a[i].f1 | (1 << (j + 1));
		}
	}
	
	dijkstra();
	
	if (dis[0] == dis[S - 1])
		std::cout << "0\n";
	else
		std::cout << dis[0] << "\n";
	
	return 0;
}
