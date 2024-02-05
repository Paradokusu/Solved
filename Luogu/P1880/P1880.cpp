#include <bits/stdc++.h>

using namespace std;

constexpr int N = 207;
constexpr int inf = 1e9;

int n, x, y, ans1 = inf, ans2 = -inf;
int a[N][N], f1[N][N], f2[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i][i]);
		a[n + i][n + i] = a[i][i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n + n - i + 1; j++) {
			x = j, y = i + j - 1;
			for (int k = 1; k < i; k++) {
				a[x][y] = a[x][x + k - 1] + a[x + k][y];
				if (f1[x][y] != 0)
					f1[x][y] = min(f1[x][y], a[x][y] + f1[x][x + k - 1] + f1[x + k][y]);
				else
					f1[x][y] = a[x][y] + f1[x][x + k - 1] + f1[x + k][y];
				
				if (f2[x][y] != 0)
					f2[x][y] = max(f2[x][y], a[x][y] + f2[x][x + k - 1] + f2[x + k][y]);
				else
					f2[x][y] = a[x][y] + f2[x][x + k - 1] + f2[x + k][y];
			}
		}
	}
	
	for (int i = 1; i <= n - 1; i++) {
		ans1 = min(ans1, f1[i][n + i - 1]);
		ans2 = max(ans2, f2[i][n + i - 1]);
	}
	
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
