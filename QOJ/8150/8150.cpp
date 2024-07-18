#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 207;
constexpr int M = 50;
constexpr int P = 1e9 + 7;

int k, C[M][M], f[M][M][N];
i64 m, n;

int dfs(int digit, int lim, int res) {  //现在在 2^digit 位，有 lim 个数达到m的上限，高于等于这个位的还需要的 value 为 res
	if (digit < 0) return res == 0;
	if (res < 0) return 0;
	if ((k / 2) * ((k + 1) / 2) * 2 - 1 < res) return 0;
	if (f[digit][lim][res] != -1) return f[digit][lim][res];
	int ret = 0;
	int add_res = digit == 0 ? 0 : n >> (digit - 1) & 1;
	if (m >> digit & 1) {
		for (int i = 0; i <= lim; ++i)
			for (int j = 0; j <= k - lim; ++j) {
				int val = (i + j) * (k - i - j);
				if (val > res) continue;
				ret += 1ll * C[lim][i] * C[k - lim][j] % P * dfs(digit - 1, i, (res - val) << 1 | add_res) % P;
				ret %= P;
			}
	} else {
		for (int j = 0; j <= k - lim; ++j) {
			int val = j * (k - j);
			if (val > res) continue;
			ret += 1ll * C[k - lim][j] * dfs(digit - 1, lim, (res - val) << 1 | add_res) % P;
			ret %= P;
		}
	}
	return f[digit][lim][res] = ret;
}

void init() {
	for (int i = 0; i <= 18; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) 
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
	memset(f, -1, sizeof(f));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	init();

	std::cin >> n >> m >> k;
	int digit = 0;
	i64 tm = m;
	while (tm / 2) { ++digit; tm /= 2; }

	if (k == 1)
		std::cout << (n == 0 ? m + 1 : 0) << "\n";
	else
		std::cout << dfs(digit, k, n >> digit) << "\n";
	return 0;
}