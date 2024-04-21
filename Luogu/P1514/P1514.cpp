#include <bits/stdc++.h>

constexpr int N = 507;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

int n, m;
bool vis[N][N];
int h[N][N], l[N][N], r[N][N];
int qx[N << 1], qy[N << 1];

void dfs(int x, int y) {
	vis[x][y] = 1;

	for (int i = 1; i <= 4; i++) {
		int fx = x + dx[i];
		int fy = y + dy[i];

		if (fx < 1 || fx > n || fy < 1 || fy > m)
			continue;

		if (h[fx][fy] >= h[x][y])
			continue;

		if (!vis[fx][fy])
			dfs(fx, fy);

		l[x][y] = std::min(l[x][y], l[fx][fy]);
		r[x][y] = std::max(r[x][y], r[fx][fy]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	memset(vis, 0, sizeof(vis));
	memset(l, 0x3f, sizeof(l));
	memset(r, -1, sizeof(r));

	for (int i = 1; i <= m; i++)
		l[n][i] = r[n][i] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> h[i][j];

	for (int i = 1; i <= m; i++)
		if (!vis[1][i])
			dfs(1, i);

	bool flg = 0;
	int cot = 0;

	for (int i = 1; i <= m; i++)
		if (!vis[n][i]) {
			flg = 1;
			cot++;
		}

	if (flg) {
		std::cout << "0\n";
		std::cout << cot << "\n";
		return 0;
	} else {
		int lft = 1;

		while (lft <= m) {
			int mxr = 0;

			for (int i = 1; i <= m; i++)
				if (l[1][i] <= lft)
					mxr = std::max(mxr, r[1][i]);

			cot++;
			lft = mxr + 1;
		}

		std::cout << "1\n";
		std::cout << cot << "\n";
	}

	return 0;
}
