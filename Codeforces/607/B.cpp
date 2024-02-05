#include <bits/stdc++.h>

using namespace std;

constexpr int N = 507;

int n;
int a[N], f[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, 0x3f, sizeof(f));
	for (int L = 0; L < n; L++) {
		for (int i = 1, j = i + L; i <= n - L; i++, j++) {
			if (a[i] == a[j])
				f[i][j] = (L < 2) ? 1 : min(f[i][j], f[i + 1][j - 1]);
			for (int k = i; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}
