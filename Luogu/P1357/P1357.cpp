#include <bits/stdc++.h>

using i64 = long long;

constexpr int S = 72;
constexpr int N = 2e5 + 7;
constexpr int MOD = 1e9 + 7;

i64 n, m;
i64 l, k, res;
i64 dp[N][S], o[S];
bool ok[S];

struct Matrix {
	i64 M[S][S];

	void Clear() {
		memset(M, 0, sizeof(M));
	}

	void Reset() {
		Clear();

		for (int i = 0; i <= l; i++)
			M[i][i] = 1;
	}

	Matrix friend operator * (const Matrix &A, const Matrix &B) {
		Matrix Ans;
		Ans.Clear();

		for (int i = 0; i <= l; i++)
			for (int j = 0; j <= l; j++)
				for (int k = 0; k <= l; k++)
					Ans.M[i][j] = (Ans.M[i][j] + A.M[i][k] * B.M[k][j]) % MOD;

		return Ans;
	}
} t, ans;

Matrix expow(Matrix T, i64 p) {
	Matrix Ans;
	Ans.Reset();

	while (p) {
		if (p & 1)
			Ans = Ans * T;

		T = T * T;
		p >>= 1;
	}

	return Ans;
}

void calc(int used, int st) {
	ok[st] = 1;
	int tst = st >> 1;
	t.M[tst][st] = 1;

	if (used == k && !(st & 1))
		return;

	t.M[tst | o[m]][st] = 1;
}

void dfs(int now, int used, int st) {
	// 用了几个花圃，几个 C 形花圃，结尾 M 个花圃状态如何

	if (now == m + 1) {
		calc(used, st);
		return;
	}

	dfs(now + 1, used, st);

	if (used < k)
		dfs(now + 1, used + 1, st | o[now]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> k;
	o[1] = 1;
	l = (1 << m) - 1;

	for (int i = 2; i <= m; i++)
		o[i] = o[i - 1] << 1;

	dfs(1, 0, 0);
	ans = expow(t, n);

	for (int i = 0; i <= l; i++)
		if (ok[i])
			(res += ans.M[i][i]) %= MOD;

	std::cout << (res % MOD) << "\n";
	return 0;
}
