#include <bits/stdc++.h>

constexpr int N = 10;
const int dx[5] = {0, -1, 0, 1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

int d, ex1, ex2, ey1, ey2;
int a[N][N];

bool check() {
	for (int i = 1; i <= 4; i++)
		if ((a[i][1] == a[i][2]) && (a[i][2] == a[i][3]) && (a[i][3] == a[i][4]))
			return 1;
	
	for (int i = 1; i <= 4; i++)
		if ((a[1][i] == a[2][i]) && (a[2][i] == a[3][i]) && (a[3][i] == a[4][i]))
			return 1;
	
	if ((a[1][1] == a[2][2]) && (a[2][2] == a[3][3]) && (a[3][3] == a[4][4]))
		return 1;
	
	if ((a[4][1] == a[3][2]) && (a[3][2] == a[2][3]) && (a[2][3] == a[1][4]))
		return 1;
	
	return 0;
}

bool dfs(int ax, int ay, int bx, int by, int col, int dep) {
	if (dep > d)  {
		if (check()) return 1;
		return 0;
	}
	
	for (int i = 1; i <= 4; i++) {
		int fx = ax + dx[i];
		int fy = ay + dy[i];
		
		if (fx > 0 && fx <= 4 && fy > 0 && fy <= 4 && a[fx][fy] == col) {
			std::swap(a[ax][ay], a[fx][fy]);
			if (dfs(fx, fy, bx, by, (col == 1) ? 2 : 1, dep + 1)) return 1;
			std::swap(a[ax][ay], a[fx][fy]);
		}
	}
	
	for (int i = 1; i <= 4; i++) {
		int fx = bx + dx[i];
		int fy = by + dy[i];
		
		if (fx > 0 && fx <= 4 && fy > 0 && fy <= 4 && a[fx][fy] == col)  {
			std::swap(a[bx][by], a[fx][fy]);
			if (dfs(ax, ay, fx, fy, (col == 1) ? 2 : 1, dep + 1)) return 1;
			std::swap(a[bx][by], a[fx][fy]);
		}
	}
	
	return 0;
}

int main() {
	for (int i = 1; i <= 4; i++)  {
		for (int j = 1; j <= 4; j++) {
			char ch;
			scanf(" %c", &ch);
			if (ch == 'B') a[i][j] = 1;
			else if (ch == 'W') a[i][j] = 2;
			else {
				if (ex1) ex2 = i, ey2 = j;
				else ex1 = i, ey1 = j;
				a[i][j] = 0;
			}
		}
	}
	
	for (d = 0;; d++) {
		if (dfs(ex1, ey1, ex2, ey2, 1, 1)) break;
		if (dfs(ex1, ey1, ex2, ey2, 2, 1)) break;
	}
	
	printf("%d\n", d);
	return 0;
}

