#include <bits/stdc++.h>

constexpr int N = 107;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, -1, 0, 1};

int n, m, t;
int r1, r2, c1, c2;
int cot[N][N][N];	// 以 (i, j) 为起点，在时间 k 内可以到达终点的路线数量
std::string a[N];

int dfs(int x, int y, int t) {
	if (cot[x][y][t] != -1)
		return cot[x][y][t];

	if (t == 0) {
		if (x == r2 && y == c2)
			return cot[x][y][t] = 1;

		return cot[x][y][t] = 0;
	}

	int sum = 0;

	for (int i = 1; i <= 4; i++) {
		int fx = x + dx[i];
		int fy = y + dy[i];

		if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && a[fx][fy] != '*')
			sum += dfs(fx, fy, t - 1);
	}

	return cot[x][y][t] = sum;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> t;
	memset(cot, -1, sizeof(cot));

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = '#' + a[i];
	}

	std::cin >> r1 >> c1 >> r2 >> c2;

	std::cout << dfs(r1, c1, t) << "\n";
	return 0;
}
