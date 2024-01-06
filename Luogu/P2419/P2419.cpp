#include <bits/stdc++.h>

using namespace std;

constexpr int N = 105;

int n, m, ans;
bitset<N> f[N];

void Floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = f[i][j] | f[i][k] & f[k][j];
	}
	
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cnt = cnt & (f[i][j] | f[j][i]);
		}
		ans += cnt;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, a, b; i <= m; i++) {
		scanf("%d %d", &a, &b);
		f[a][b] = 1;
	}
	Floyd();
	printf("%d\n", ans);
	return 0;
}
