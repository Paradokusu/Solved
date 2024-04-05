#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 13;
constexpr int M = 1 << N;
constexpr int inf = 0x3f3f3f3f;

int n, m;
int pw[N], dis[N][N], trans[M][M];
i64 dp[N][M];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));

	for (int i = 1; i <= m; i++) {
		int s, t, v;
		std::cin >> s >> t >> v;

		if (dis[s][t] > v)
			dis[s][t] = dis[t][s] = v;
	}

	m = (1 << n);
	pw[0] = 1;

	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2;

	for (int i = 0; i < m; i++) {
		for (int j = i; j != 0; j = (j - 1) & i) {
			bool flg = 1;
			int tmp = i ^ j;

			for (int k = n - 1; k >= 0; k--) {
				if (tmp >= pw[k]) {
					int tmin = inf;

					for (int o = 1; o <= n; o++)
						if ((pw[o - 1] & j) == pw[o - 1])
							tmin = std::min(tmin, dis[o][k + 1]);

					if (tmin == inf) {
						flg = 0;
						break;
					}

					trans[j][i] += tmin;
					tmp -= pw[k];
				}
			}

			if (flg == 0)
				trans[j][i] = inf;
		}
	}

	memset(dp, 0x3f, sizeof(dp));

	for (int i = 1; i <= n; i++)
		dp[1][pw[i - 1]] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < m; j++)
			for (int k = j; k != 0; k = (k - 1) & j)
				if (trans[k][j] != inf)
					dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + (i - 1) * trans[k][j]);
	}

	i64 ans = LLONG_MAX;

	for (int i = 1; i <= n; i++)
		ans = std::min(ans, dp[i][m - 1]);

	std::cout << ans << "\n";
	return 0;
}
