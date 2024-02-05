#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1007;

int n, m, p;
int gts[N][N], cst[N], dp[N];

int main() {
	scanf("%d %d %d", &n, &m, &p);
	
	memset(dp, -0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &gts[i][j]);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &cst[i]);
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int df = j - 1;
			if (!df) df = n;
			int sum = gts[df][i];
			for (int k = 1; k <= p; k++) {
				if (i - k < 0)
					break;
				dp[i] = max(dp[i], dp[i - k] + sum - cst[df]);
				df--;
				if (!df) df = n;
				sum += gts[df][i - k];
			}
		}
	}
	
	printf("%d\n", dp[m]);
	return 0;
}
