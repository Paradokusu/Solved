#include <bits/stdc++.h>

constexpr int N = 15;
const int b[6][6] = {{},
               {0, 1, 1, 1, 1, 1},
               {0, 0, 1, 1, 1, 1},
               {0, 0, 0, -1, 1, 1},
               {0, 0, 0, 0, 0, 1},
               {0, 0, 0, 0, 0, 0}};
const int dx[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
const int dy[8] = {-1, 1, 2, 2, -2, -2, -1, 1};

int T, maxd;
int a[N][N];

int check(int k, int x, int y, int sum, int la) {
	if (k + sum > maxd) return 0;
	if (sum == 0) return 1;
	
	bool flg1 = 0;
	
	for (int i = 0; i <= 7; i++) {
		if (i != (7 - la)) {
			int fx = x + dx[i], fy = y + dy[i], p = sum;
			
			if (fx <= 5 && fx > 0 && fy <= 5 && fy > 0) {
				if (a[fx][fy] == b[fx][fy] && a[fx][fy] != b[x][y]) ++p;
				if (a[fx][fy] != b[fx][fy] && a[fx][fy] == b[x][y]) --p;
				if (b[fx][fy] == -1) p--;
				if (b[x][y] == -1) p++;
				
				a[fx][fy] ^= a[x][y];
				a[x][y] ^= a[fx][fy];
				a[fx][fy] ^= a[x][y];
				
				flg1 = check(k + 1, fx, fy, p, i);
				if (flg1) return 1;
				
				a[fx][fy] ^= a[x][y];
				a[x][y] ^= a[fx][fy];
				a[fx][fy] ^= a[x][y];
			}
		}
	}
	
	return 0;
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		int mn = 0, x, y;
		for (int i = 1; i <= 5; i++)
			for (int j = 1; j <= 5; j++) {
				char ch;
				scanf(" %c", &ch);
				if (ch == '*') {
					a[i][j] = -1;
					x = i, y = j;
				} else a[i][j] = ch - '0';
				if (a[i][j] != b[i][j])
					mn++;
			}
		
		bool flg = 0;
		for (int i = mn; i <= 16; i++) {
			maxd = i;
			if (check(0, x, y, mn, -1)) {
				printf("%d\n", i - 1);
				flg = 1;
				break;
			}
		}
		
		if (!flg)
			printf("-1\n");
	}
	
	return 0;
}

