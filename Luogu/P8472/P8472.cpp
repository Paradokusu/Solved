#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e2 + 7;

int n, m, k, ans;
int ix, iy, jx, jy;
int br[N][N], gr[N][N], pu[N][N];
char oc, f[N][N];

bool cb(int ax, int ay, int bx, int by) {
	int sumb = br[bx][by] - br[bx][ay - 1] - br[ax - 1][by] + br[ax - 1][ay - 1];
	int sump = pu[bx][by] - pu[bx][ay - 1] - pu[ax - 1][by] + pu[ax - 1][ay - 1];
	
	if (sump) return 0;
	if ((bx - ax + 1) * (by - ay + 1) - sumb <= k)
		return 1;
	return 0;
}

bool cg(int ax, int ay, int bx, int by) {
	int sumg = gr[bx][by] - gr[bx][ay - 1] - gr[ax - 1][by] + gr[ax - 1][ay - 1];
	int sump = pu[bx][by] - pu[bx][ay - 1] - pu[ax - 1][by] + pu[ax - 1][ay - 1];
	
	if (sump) return 0;
	if ((bx - ax + 1) * (by - ay + 1) - sumg <= k)
		return 1;
	return 0;
}

bool cp(int ax, int ay, int bx, int by) {
	int sump = pu[bx][by] - pu[bx][ay - 1] - pu[ax - 1][by] + pu[ax - 1][ay - 1];
	
	if ((bx - ax + 1) * (by - ay + 1) == sump)
		return 1;
	return 0;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", f[i] + 1);
		for (int j = 1; j <= m; j++) {
			br[i][j] = br[i - 1][j] + br[i][j - 1] - br[i - 1][j - 1] + (f[i][j] == 'B');
			gr[i][j] = gr[i - 1][j] + gr[i][j - 1] - gr[i - 1][j - 1] + (f[i][j] == 'G');
			pu[i][j] = pu[i - 1][j] + pu[i][j - 1] - pu[i - 1][j - 1] + (f[i][j] == 'P');
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int l = 1, r = 0; l <= m && r <= m; l++) {
				while (r < m && cb(i, l, j, r + 1)) r++;
				if ((r - l + 1) * (j - i + 1) > ans) {
					ans = (r - l + 1) * (j - i + 1);
					ix = i, iy = l, jx = j, jy = r;
					oc = 'B';
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int l = 1, r = 0; l <= m && r <= m; l++) {
				while (r < m && cg(i, l, j, r + 1)) r++;
				if ((r - l + 1) * (j - i + 1) > ans) {
					ans = (r - l + 1) * (j - i + 1);
					ix = i, iy = l, jx = j, jy = r;
					oc = 'G';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int l = 1, r = 0; l <= m && r <= m; l++) {
				while (r < m && cp(i, l, j, r + 1)) r++;
				if ((r - l + 1) * (j - i + 1) > ans) {
					ans = (r - l + 1) * (j - i + 1);
					ix = i, iy = l, jx = j, jy = r;
					oc = 'P';
				}
			}
		}
	}
	
	for (int i = ix; i <= jx; i++) {
		for (int j = iy; j <= jy; j++)
			f[i][j] = oc;
	}
	
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%c", f[i][j]);
		printf("\n");
	}
	
	return 0;
}
