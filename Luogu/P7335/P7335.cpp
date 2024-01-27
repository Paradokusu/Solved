#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3007;

int n, k;
int a[N], num[N], mx[N][N];
i64 f[N][2];

struct len {
	int l, r, w;
} s[N][N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1, in; i <= n; i++) {
		scanf("%d", &in);
		a[i] = in ^ a[i - 1];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1, p = 0; j >= 0; j--) {
			if ((a[i] ^ a[j]) > p)
				p = (a[i] ^ a[j]);
			mx[j][i] = std::max(mx[j][i - 1], p);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		s[i][1].l = 0;
		s[i][1].r = 0;
		s[i][1].w = mx[0][i];
		num[i] = 1;
		
		for (int j = 1; j < i; j++) {
			if (mx[j][i] == mx[j - 1][i])
				s[i][num[i]].r++;
			else {
				s[i][++num[i]].l = j;
				s[i][num[i]].r = j;
				s[i][num[i]].w = mx[j][i];
			}
		}
	}
	
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j % 2] = 0;
			for (int x = 1; x <= num[i]; x++) {
				f[i][j % 2] = std::max(f[i][j % 2], f[s[i][x].r][(j % 2) ^ 1] + s[i][x].w);
			}
		}
	}
	
	printf("%lld\n", f[n][k % 2]);
	return 0;
} 

