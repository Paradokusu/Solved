#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

int n, m;
int f[N][N], cst[N][N];

struct node {
	int eid;
	int a[N];
} way[N][N];

int main() {
	memset(f, -0x3f, sizeof(f));

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &cst[i][j]);
	}
	
	for (int i = 0; i <= m; i++)
		f[0][i] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			if (f[i - 1][j - 1] + cst[i][j] > f[i][j - 1]) {
				way[i][j] = way[i - 1][j - 1];
				way[i][j].a[++way[i][j].eid] = j;
				f[i][j] = f[i - 1][j - 1] + cst[i][j];
			} else {
				way[i][j] = way[i][j - 1];
				f[i][j] = f[i][j - 1];
			}
		}
	}
	
	printf("%d\n", f[n][m]);
	for (int i = 1; i <= way[n][m].eid; i++)
		printf("%d ", way[n][m].a[i]);
	return 0;
}
