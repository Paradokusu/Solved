#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

int n, q;
int siz[N], son[N][2], val[N][2], dp[N][N];

void Gma(int &x, int y) {
	x < y ? x = y : 0;
}

void dfs(int u) {
	int x = son[u][0], y = son[u][1];
	if (!x && !y) return;
	dfs(x);
	dfs(y);
	siz[u] = siz[x] + siz[y] + 2;
	for (int i = -1; i <= siz[x]; i++) {
		for (int j = -1; j <= siz[y]; j++) {
			int vl = i == -1 ? 0 : dp[x][i] + val[u][0];
			int vr = j == -1 ? 0 : dp[y][j] + val[u][1];
			Gma(dp[u][i + j + 2], vl + vr);
		}
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1, in; i < n; i++) {
		scanf("%d", &in);
		int ch =  son[in][0] > 0;
		scanf("%d %d", &son[in][ch], &val[in][ch]);
	}
	
	dfs(1);
	
	printf("%d\n", dp[1][q]);
	return 0;
}
