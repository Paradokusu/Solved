#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;
constexpr double eps = 1e-6;

int n, curl;
double a[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			scanf("%lf", &a[i][j]);
	for (int j = 0; j < n; j++) {
		int t;
		for (t = curl; t < n; t++)
			if (fabs(a[t][j]) > eps)	// 找非 0 元素
				break;
		if (t == n) continue;	// 本列无非 0 元素
		for (int i = j; i <= n; i++)
			swap(a[t][i], a[curl][i]);	// 交换非 0 元素行到当前行
		for (int i = n; i >= j; i--)
			a[curl][i] /= a[curl][j];
		for (int i = 0; i < n; i++)
			if (i != curl)
				for (int k = n; k >= j; k--)
					a[i][k] -= a[curl][k] * a[i][j];
		curl++;
	}
	
	if (curl < n) {
		for (int i = curl; i < n; i++)
			if (fabs(a[i][n]) > eps) {
				printf("-1\n");
				exit(0);
			}
	} else
		for (int i = 0; i < n; i++)
			printf("x%d=%.2lf\n", i + 1, a[i][n]);
	
	return 0;
}

/*
* Hack:
3
0 1 1 2
0 0 3 9
0 0 5 15
*/
