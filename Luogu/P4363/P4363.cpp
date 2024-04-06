#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 15;
constexpr int M = 1e6 + 7;
constexpr int BASE = 233;
constexpr int MOD = 998244353;

int n, m, tot;
int cot[N], base[N];
int A[N][N], B[N][N];

std::map<i64, int> h;
std::vector<int> s[M];

i64 Get() {
	i64 res = 0;

	for (int i = 1; i <= n; i++)
		res = (res * BASE + cot[i]) % MOD;

	return res;
}

int mn, dep;
int id[M], rev[M], val[M];
int dp[2][M];

void dfs() {
	++dep;

	if (!h[Get()]) {
		++tot;
		mn = m + 1;
		h[Get()] = tot;

		for (int i = 1; i <= n; i++) {
			s[tot].push_back(cot[i]);
			mn = std::min(mn, cot[i]);
			val[tot] += cot[i];
		}

		if (mn == m)
			return;
	} else
		return;

	for (int i = 1; i <= n; i++) {
		if (cot[i] >= m || cot[i] >= cot[i - 1])
			continue;
		cot[i]++; dfs(); cot[i]--;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	cot[0] = m + 1;

	dfs();

	for (int i = 1; i <= tot; i++)
		id[i] = i;
	
	std::sort(id + 1, id + tot + 1, [](int x, int y) {
		return val[x] > val[y];
	});

	for (int i = 1; i <= tot; i++)
		rev[id[i]] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> A[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> B[i][j];

	memset(dp[1], 0x3f, sizeof(dp[1]));
	memset(dp[0], -0x3f, sizeof(dp[0]));

	if ((n * m) & 1)
		dp[1][1] = 0;
	else
		dp[0][1] = 0;

	for (int i = 1; i < tot; i++) {
		int x = id[i], y = 0, t = 0, z, o;

		for (auto p = s[x].begin(); p != s[x].end(); p++) {
			++t;
			y = 0;
			int mv = m;

			for (auto q = s[x].begin(); q != s[x].end(); q++) {
				int x = *q;
				cot[++y] = x;

				if (p == q)
					cot[y]--, o = cot[y];

				if (mv < cot[y])
					goto cc;

				mv = std::min(cot[y], mv);
			}

			if (!(z = h[Get()]))
				continue;

			if (dp[0][i] < MOD)
				dp[1][rev[z]] = std::min(dp[1][rev[z]], dp[0][i] - B[t][o + 1]);

			if (dp[1][i] < MOD)
				dp[0][rev[z]] = std::max(dp[0][rev[z]], dp[1][i] + A[t][o + 1]);

			cc:
				continue;
		}
	}

	std::cout << dp[0][tot] << "\n";
	return 0;
}
