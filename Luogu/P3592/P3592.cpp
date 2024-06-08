#include <bits/stdc++.h>

using namespace std;

constexpr int N = 50 + 7;
constexpr int M = 4000 + 7;
constexpr int inf = numeric_limits<int>::max();

int n, m, cot;	// cot 表示穿过在 [i, j] 内 (a, b) 穿过的 pos 数量
int a[M], b[M], c[M], d[M], ans[M];
int g[N][M];
/*
* f[i][j][k]: 区间 f[i, j] 最小值为 k 时 k 的位置
* mx[i][j][k]: 最大的 l (l >= k) 使得 dp[i][j][l] 最大
* pre[i][j][k]: mx[i][j][k] 的 l
*/
int f[N][N][M], pre[N][N][M], mx[N][N][M];

void dget(int l, int r, int k) {
	if (l > r) return;
	int pos = f[l][r][k = pre[l][r][k]];
	ans[pos] = d[k];
	dget(l, pos - 1, k);
	dget(pos + 1, r, k);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		d[i] = c[i];
	}
	
	sort(d + 1, d + m + 1);
	cot = unique(d + 1, d + m + 1) - d - 1;
	for (int i = 1; i <= m; i++)
		c[i] = lower_bound(d + 1, d + cot + 1, c[i]) - d;
	
	for (int i = n; i; i--) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= j; k++)
				for (int l = 0; l <= cot; l++)
					g[k][l] = 0;
			for (int k = 1; k <= m; k++)
				if (i <= a[k] && b[k] <= j)
					for (int l = a[k]; l <= b[k]; l++)
						g[l][c[k]]++;
			for (int k = i; k <= j; k++)
				for (int l = cot - 1; l; l--)
					g[k][l] += g[k][l + 1];
			for (int k = cot; k; k--) {
				int mxn = -inf;
				for (int l = i; l <= j; l++) {
					int val = mx[i][l - 1][k] + mx[l + 1][j][k] + g[l][k] * d[k];
					if (mxn <= val) {
						mxn = val;
						f[i][j][k] = l;
					}
				}
				if (mxn >= mx[i][j][k + 1]) {
					mx[i][j][k] = mxn;
					pre[i][j][k] = k;
				} else {
					mx[i][j][k] = mx[i][j][k + 1];
					pre[i][j][k] = pre[i][j][k + 1];
				}
			}
		}
	}
	
	dget(1, n, 1);
	
	printf("%d\n", mx[1][n][1]);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
