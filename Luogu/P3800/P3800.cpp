#include <bits/stdc++.h>

using namespace std;

constexpr int N = 4007;

int n, m, K, T;
int A[N][N], f[N][N];

int main() {
	scanf("%d %d %d %d", &n, &m, &K, &T);
	for (int i = 1; i <= K; i++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		A[x][y] = v;
	}
	for (int i = 1; i <= n; i++) {
		static int q[N];
		int head = 1, tail = 0, r = 0;
		const int *g = f[i - 1];
		for (int j = 1; j <= m; j++) {
			while (r < m && r < j + T) {
				++r;
				// fresh
				while (head <= tail && g[q[tail]] <= g[r])
					tail--;
				q[++tail] = r;
			}
			// check
			while (head <= tail && q[head] < j - T)
				head++;
			// the front of the queue must be the max num in the section because of the monotonicity
			f[i][j] = (head <= tail ? g[q[head]] : 0) + A[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}

