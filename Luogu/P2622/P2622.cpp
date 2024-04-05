#include <bits/stdc++.h>

constexpr int N = 107;

int n, m;
int a[N][N];
bool vis[N * N];

struct node {
	int s, step;
};

int SPFA() {
	int p;
	std::queue<node> q;

	q.push({(1 << n) - 1, 0});
	vis[(1 << n) - 1] = 1;	// 全开

	while (!q.empty()) {
		node u = q.front();
		q.pop();

		if (u.s == 0)
			return u.step;

		for (int i = 1; i <= m; i++) {
			p = u.s;

			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 1 && (p & (1 << (j - 1))))
					p ^= (1 << (j - 1));
				else if (a[i][j] == -1 && !(p & (1 << (j - 1))))
					p |= (1 << (j - 1));
			}

			if (!vis[p]) {
				q.push({p, u.step + 1});
				vis[p] = 1;
			}
		}
	}

	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];
	}

	std::cout << SPFA() << "\n";

	return 0;
}
