#include <bits/stdc++.h>

using namespace std;

constexpr int N = 307;
constexpr int inf = 2147483647;

int n;
int a[N], f[N][N], w[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			w[i][j] = w[i][j - 1] + a[j];
	}

	for (int L = 1; L < n; L++) {
		for (int i = 1; i + L <= n; i++) {
			int j = i + L, &fij = f[i][j];
			fij = inf;
			for (int k = i; k < j; k++)
				fij = min(fij, f[i][k] + f[k + 1][j]);
			fij += w[i][j];
		}
	}
	
	printf("%d\n", f[1][n]);
	return 0;
}
