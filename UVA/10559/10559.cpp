#include <bits/stdc++.h>

constexpr int N = 200 + 7;
constexpr int M = N << 1;

int T;
int n, cnt, lst;
int clr[N], len[N], f[N][N][M];

void init() {
	cnt = 0, lst = -1;
	memset(f, 0, sizeof(f));
	memset(clr, 0, sizeof(clr));
	memset(len, 0, sizeof(len));
}

int dfs(int l, int r, int k) {
	if (f[l][r][k]) return f[l][r][k];
	if (l == r) return (len[r] + k) * (len[r] + k);
	f[l][r][k] = dfs(l, r - 1, 0) + (len[r] + k) * (len[r] + k);
	for (int i = l; i < r - 1; i++)
		if(clr[i] == clr[r])
			f[l][r][k] = std::max(f[l][r][k], dfs(l, i, len[r] + k) + dfs(i + 1, r - 1, 0));
	return f[l][r][k];
}

void solve(int c) {
	scanf("%d", &n);
	for (int i = 1, inp; i <= n; i++) {
		scanf("%d", &inp);
		if (inp == lst) len[cnt]++;
		else {
			clr[++cnt] = inp;
			len[cnt]++;
		}
		lst = inp;
	}
	printf("Case %d: %d\n", c, dfs(1, cnt, 0));
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		init();
		solve(i);
	}
	return 0;
}

