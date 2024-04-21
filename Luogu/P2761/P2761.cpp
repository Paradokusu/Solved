#include <bits/stdc++.h>

constexpr int N = 107;
constexpr int S = 4e6 + 7;

int n, m, st;

struct node {
	int b1, b2, f1, f2, t;
} a[N << 1];

std::priority_queue<std::pair<int, int>> q;

int dis[S], _hash[S];

void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	q.push({0, st});

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		if (_hash[now] == 1)
			continue;

		_hash[now] = 1;

		// 好多轻小说国内都被 BAN 了，肥王东西还在上，中华书局感觉已经要死了

		for (int i = 1; i <= m; i++) {
			if ((a[i].b1 & now) == a[i].b1 && (a[i].b2 & now) == 0) {
				int v = ((now | ))
			}
		}
	}
}

int main() {
	
}
