#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1007;

i64 n, m;
i64 dis[N][N], cot[N][N];
double ans[N];

void Floyd() {
	for (i64 k = 1; k <= n; k++) {
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = 1; j <= n; j++) {
				i64 c = dis[i][k] + dis[k][j];

				if (dis[i][j] == c)
					cot[i][j] += cot[i][k] * cot[k][j];
				else if (dis[i][j] > c) {
					dis[i][j] = c;
					cot[i][j] = cot[i][k] * cot[k][j];
				}
			}
		}
	}

	for (i64 v = 1; v <= n; v++) {
		for (i64 s = 1; s <= n; s++) {
			if (s != v) {
				for (i64 t = 1; t <= n; t++) {
					if (t != v && t != s) {
						if (dis[s][t] == dis[s][v] + dis[v][t])
							ans[v] += 1.0 * cot[s][v] * cot[v][t] / cot[s][t];
					}
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));

	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		dis[a][b] = dis[b][a] = c;
		cot[a][b] = cot[b][a] = 1;
	}

	Floyd();

	for (int i = 1; i <= n; i++)
		std::cout << std::fixed << std::setprecision(3) << ans[i] << "\n";

	return 0;
}
