#include <bits/stdc++.h>

constexpr int N = 6;

char g[N][N], backup[N][N];
std::vector<int> dx = {-1, 0, 1, 0, 0}, dy = {0, 1, 0, -1, 0};

void turn(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int a = x + dx[i], b = y + dy[i];

		if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
		g[a][b] ^= 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		for (int i = 0; i < 5; i++) 
			std::cin >> g[i];

		int res = 10;
		for (int op = 0; op < 32; op++) {
			memcpy(backup, g, sizeof(backup));

			int step = 0;
			for (int i = 0; i < 5; i++) {
				if ((op >> i) & 1) {
					step++;
					turn(0, i);
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 5; j++) {
					if (g[i][j] == '0') {
						step++;
						turn(i + 1, j);
					}
				}
			}
			bool flag = false;
			for (int i = 0; i < 5; i++) {
				if (g[4][i] == '0') {
					flag = true;
					break;
				}
			}

			if (!flag) res = std::min(res, step);
			memcpy(g, backup, sizeof(g));
		}
		if (res > 6) res = -1;
		std::cout << res << "\n";
	}
	return 0;
}
