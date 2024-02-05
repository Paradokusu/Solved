#include <bits/stdc++.h>

using namespace std;

constexpr int N = 45;
constexpr int M = 350 + 7;

int n, m;
int val[M], cnt[N], dp[N][N][N][N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (int i = 1, in; i <= m; i++) {
		scanf("%d", &in);
		cnt[in]++;
	}
	
	dp[0][0][0][0] = val[1];
	for (int a = 0; a <= cnt[1]; a++) {
		for (int b = 0; b <= cnt[2]; b++)
			for (int c = 0; c <= cnt[3]; c++)
				for (int d = 0; d <= cnt[4]; d++) {
					int w = 1 + a + b * 2 + c * 3 + d * 4;
					if (a != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + val[w]);
					if (b != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + val[w]);
					if (c != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + val[w]);
					if (d != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + val[w]);
				}
	}
	
	printf("%d\n", dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
	return 0;
}
