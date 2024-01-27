#include <bits/stdc++.h>

constexpr int inf = 1e9;

const int dx[8] = {0, 1, 0, -1, 1, -1, -1, 1};
const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

struct node {
	int x, y;
};

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> a[n * m + 1], f[n * m + 1], ans[n * m + 1], inq[n * m + 1];
	std::vector<node> isLand;
	std::queue<node> bfsQ;

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			std::cin >> c;
			
			f[i].push_back(inf);
			ans[i].push_back(0);
			inq[i].push_back(0);
			while (c != '.' && c != 'v' && c != '#')
				std::cin >> c;

			if (c == '.') a[i].push_back(0);
			if (c == 'v') {
				a[i].push_back(1);
				bfsQ.push({i, j});
				f[i][j] = 0;
			}
			if (c == '#') {
				a[i].push_back(2);
				isLand.push_back({i, j});
			}
		}
	}

	while (!bfsQ.empty()) {
		int fx = bfsQ.front().x, fy = bfsQ.front().y;
		bfsQ.pop();

		for (int k = 0; k < 4; k++) {
			int nx = fx + dx[k], ny = fy + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (f[nx][ny] <= f[fx][fy] + 1) continue;
			f[nx][ny] = f[fx][fy] + 1;
			bfsQ.push({nx, ny});
		}
	}

	std::function<bool(int, int, int)> check = [&](int x, int qx, int qy) {
		std::queue<node> emptyQ;
		bfsQ = emptyQ;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				inq[i][j] = 0;
		bfsQ.push({qx, qy});
		inq[qx][qy] = 1;

		while (!bfsQ.empty()){
			int sx = bfsQ.front().x, sy = bfsQ.front().y;
			bfsQ.pop();
			for (int k = 0; k < 4; k++) {
				int nx = sx + dx[k], ny = sy + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (f[nx][ny] < x || inq[nx][ny] || a[nx][ny] == 2) continue;
				bfsQ.push({nx, ny});
				inq[nx][ny] = 1;
			}
		}

		for (auto i : isLand){
			bfsQ.push(i);
			inq[i.x][i.y] = 1;
		}

		while (!bfsQ.empty()) {
			int sx = bfsQ.front().x, sy = bfsQ.front().y;
			bfsQ.pop();
			if (sx == 0 || sx == n - 1 || sy == 0 || sy == m - 1) return 0;
			for (int k = 0; k < 8; k++) {
				int nx = sx + dx[k], ny = sy + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (inq[nx][ny]) continue;
				bfsQ.push({nx, ny});
				inq[nx][ny] = 1;
			}
		}

		return 1;
	};

	while (q--) {
		int qx, qy;
		std::cin >> qx >> qy;
		qx--, qy--;
		int l = 0, r = f[qx][qy], dis = 0;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, qx, qy))
				l = mid + 1, dis = mid;
			else
				r = mid - 1;
		}

		std::cout << dis << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}
