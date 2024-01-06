#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;

int n, q, lg, top;
int d[N], c[N], stc[N];
int f[N][20], to[N][20];

int main() {
	scanf("%d %d", &n, &q);
	lg = __lg(n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &d[i], &c[i]);
	
	for (int i = n; i; i--) {
		while (top && d[i] >= d[stc[top]]) top--;
		to[i][0] = stc[top], f[i][0] = c[i], stc[++top] = i;
	}
	
	for (int j = 1; j <= lg + 1; j++)
		for (int i = 1; i <= n; i++)
			to[i][j] = to[to[i][j - 1]][j - 1], f[i][j] = f[i][j - 1] + f[to[i][j - 1]][j - 1];
	
	for (int i = 1; i <= q; i++) {
		int p, r;
		scanf("%d %d", &p, &r);
		for (int j = lg + 1; ~j; j--)
			if (r > f[p][j])
				r -= f[p][j], p = to[p][j];
		printf("%d\n", p);
	}
	
	return 0;
}
