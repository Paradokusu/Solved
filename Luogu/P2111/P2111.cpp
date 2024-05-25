#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10007;

int n, a, q;
long double ans, P;
long double f[N][N];

int main() {
	scanf("%d %d %d", &n, &a, &q);
	if (n > 50) {
		printf("1.000\n");
		exit(0);
	}
	
	P = a / 100.0;
	f[0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf(" %c", &ch);
		for (int j = 0; j <= i; j++) {
			if (ch == '0')
				f[i][j] = f[i - 1][j] * P + f[i - 1][j - 1] * (1 - P);
			else
				f[i][j] = f[i - 1][j - 1] * P + f[i - 1][j] * (1 - P);
		}
	}
	
	for (int i = n; i >= q; i--)
		ans += f[n][i];
	printf("%.3Lf\n", ans);
	return 0;
}
