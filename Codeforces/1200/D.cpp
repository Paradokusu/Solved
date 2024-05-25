#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2000 + 7;

int n, k;
int sum[N][N];
char mp[N][N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf(" %c", &mp[i][j]);
	}
	
	for (int i = 1; i <= n; i++) {
		int ly = 1, ry = n - k + 1;
		int lx = 1, rx = n - k + 1;
		
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == 'B') {
				lx = max(lx, i - k + 1), rx = min(rx, i);
				ly = max(ly, j - k + 1), ry = min(ry, j);
			}
		}
		
		if (lx > rx) continue;
		if (ly > ry) continue;
		
		sum[lx][ly]++, sum[lx][ry + 1]--, sum[rx + 1][ly]--, sum[rx + 1][ry + 1]++;
	}
	
	for (int j = 1; j <= n; j++) {
		int ly = 1, ry = n - k + 1;
		int lx = 1, rx = n - k + 1;
		
		for (int i = 1; i <= n; i++) {
			if (mp[i][j] == 'B') {
				lx = max(lx, i - k + 1), rx = min(rx, i);
				ly = max(ly, j - k + 1), ry = min(ry, j);
			}
		}
		
		if (lx > rx) continue;
		if (ly > ry) continue;
		
		sum[lx][ly]++, sum[lx][ry + 1]--, sum[rx + 1][ly]--, sum[rx + 1][ry + 1]++;
	}
	
	int ans = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			ans = max(ans, sum[i][j]);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
