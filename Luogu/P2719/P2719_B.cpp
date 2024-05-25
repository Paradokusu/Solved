#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1250 + 7;

int n;
double f[N][N];	// 剩下 x 张 A 类和 y 张 B 类

int main() {
	scanf("%d", &n);
	n >>= 1;
	
	for (int i = 2; i <= n; i++)
		f[i][0] = f[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = 0.5 * (f[i - 1][j] + f[i][j - 1]);
	
	printf("%.4lf", f[n][n]);
	return 0;
}
