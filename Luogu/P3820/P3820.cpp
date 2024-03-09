#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, q, cnt;
int siz[N << 1];

std::string s[N];
std::vector<std::vector<int>> bl;

bool Check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y, int id) {
	static int qx[N], qy[N], qn;

	if (bl[x][y] != id) {
		siz[bl[x][y]] = 0;
		bl[x][y] = id;
		siz[id]++;
	}

	qx[1] = x, qy[1] = y, qn = 1;

	for (int i = 1; i <= qn; i++) {
		x = qx[i], y = qy[i];

		for (int d = 0; d <= 3; d++) {
			int fx = x + dx[d], fy = y + dy[d];

			if (Check(fx, fy) && s[fx][fy] == '.' && bl[fx][fy] != id) {
				siz[bl[fx][fy]] = 0;
				bl[fx][fy] = id;
				siz[id]++;

				qx[++qn] = fx;
				qy[qn] = fy;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	static std::vector<int> vi(m, 0);

	for (int i = 0; i < n; i++) {
		bl.push_back(vi);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.' && !bl[i][j]) {
				++cnt;
				bfs(i, j, cnt);
			}
		}
	}

	std::cin >> q;

	while (q--) {
		int opt, w, x, y;
		std::cin >> opt >> w;

		if (opt == 1) {
			int ans = -1, id;

			for (int i = 1; i <= w; i++) {
				std::cin >> x >> y;
				x--, y--;

				if (siz[bl[x][y]] > ans) {
					ans = siz[bl[x][y]];
					id = i;
				}
			}

			std::cout << id << "\n";
		} else {
			for (int i = 1; i <= w; i++) {
				std::cin >> x >> y;
				x--, y--;

				if (s[x][y] == '*') {
					int mxsiz = -1, id = 0;

					for (int d = 0; d <= 3; d++) {
						int fx = x + dx[d], fy = y + dy[d];

						if (Check(fx, fy) && s[fx][fy] == '.' && siz[bl[fx][fy]] > mxsiz) {
							mxsiz = siz[bl[fx][fy]];
							id = bl[fx][fy];
						}
					}

					if (!id) {
						bl[x][y] = ++cnt;
						siz[cnt] = 1;
					} else {
						bl[x][y] = id;
						siz[id]++;

						for (int d = 0; d <= 3; d++) {
							int fx = x + dx[d], fy = y + dy[d];

							if (Check(fx, fy) && s[fx][fy] == '.' && bl[fx][fy] != id) {
								bfs(fx, fy, id);
							}
						}
					}

					s[x][y] = '.';
				} else {
					siz[bl[x][y]]--;
					bl[x][y] = 0;
					s[x][y] = '*';
				}
			}
		}
	}

	return 0;
}
