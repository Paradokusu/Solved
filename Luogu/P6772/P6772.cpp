#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 307;

int n, m, T, K, val[N];
i64 A[35][N][N];

struct Celebration {
	int t, u, v;
} ts[N];

bool cmp(const Celebration &a, const Celebration &b) { return a.t < b.t; }

int Get(int t, int x) { return t * n + x - 1; }

void Gma(i64 &x, i64 y) { x < y ? x = y : 0; }

int main() {
	// freopen("delicacy.in", "r", stdin);
	// freopen("delicacy.out", "w", stdout);
	
	scanf("%d %d %d %d", &n, &m, &T, &K);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	
	memset(A, 0xcf, sizeof A);
	for (int i = 1; i <= m; i++) {
		int b, e, w;
		scanf("%d %d %d", &b, &e, &w);
		A[0][Get(4, e)][Get(5 - w, b)] = val[e];
	}
	
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= n; j++)
			A[0][Get(i, j)][Get(i + 1, j)] = 0;
	
	const static int lim = n * 5;
	for (int i = 0; i != 30; i++) {
		for (int j = 0; j < lim; j++)
			for (int k = 0; k < lim; k++)
				for (int l = 0; l < lim; l++)
					Gma(A[i + 1][j][l], A[i][j][k] + A[i][k][l]);
	}
	
	static i64 dp[2][N];
	memset(dp, 0xcf, sizeof dp);
	int now = 0, lst = 1;
	dp[now][Get(4, 1)] = val[1];
	
	auto trans = [&](int dt) {
		for (int j = 0; j != 31; j++)
			if (dt >> j & 1) {
				swap(now, lst);
				memset(dp[now], 0xcf, sizeof dp[now]);
				for (int k = 0; k < lim; k++)
					for (int l = 0; l < lim; l++)
						Gma(dp[now][k], dp[lst][l] + A[j][k][l]);
			}
	};
	
	for (int i = 1; i <= K; i++)
		scanf("%d %d %d", &ts[i].t, &ts[i].u, &ts[i].v);
	
	sort(ts + 1, ts + K + 1, cmp);
	
	for (int i = 1; i <= K; i++) {
		int delta = ts[i].t - ts[i - 1].t;
		trans(delta);
		dp[now][Get(4, ts[i].u)] += ts[i].v;
	}
	
	trans(T - ts[K].t);
	i64 ans = dp[now][Get(4, 1)];
	if (ans < 0)
		ans = -1;
	printf("%lld\n", ans);
	return 0;
}
