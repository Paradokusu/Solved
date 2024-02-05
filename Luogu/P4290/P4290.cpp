#include <bits/stdc++.h>

using namespace std;

constexpr int N = 207;

int qw, qi, qn, qg, val[N];
bool cbn[N][N][5], ok[N][N][5];
char a, b, c[N];

void Exchange(int x) {
	int fa, fb;
	
	if (a == 'W') fa = 1;
	else if (a == 'I') fa = 2;
	else if (a == 'N') fa = 3;
	else if (a == 'G') fa = 4;
	
	if (b == 'W') fb = 1;
	else if (b == 'I') fb = 2;
	else if (b == 'N') fb = 3;
	else if (b == 'G') fb = 4;
	
	ok[fa][fb][x] = 1;
}

int main() {
	scanf("%d %d %d %d", &qw, &qi, &qn, &qg);
	for (int i = 1; i <= qw; i++) {
		scanf(" %c %c", &a, &b);
		Exchange(1);
	}
	for (int i = 1; i <= qi; i++) {
		scanf(" %c %c", &a, &b);
		Exchange(2);
	}
	for (int i = 1; i <= qn; i++) {
		scanf(" %c %c", &a, &b);
		Exchange(3);
	}
	for (int i = 1; i <= qg; i++) {
		scanf(" %c %c", &a, &b);
		Exchange(4);
	}
	
	scanf("%s", c + 1);
	int n = strlen(c + 1);
	
	for (int i = 1; i <= n; i++) {
		if (c[i] == 'W') val[i] = 1;
		else if (c[i] == 'I') val[i] = 2;
		else if (c[i] == 'N') val[i] = 3;
		else if (c[i] == 'G') val[i] = 4;
	}
	
	for (int i = 1; i <= n; i++)
		cbn[i][i][val[i]] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 1; j + i - 1 <= n; j++) {
			int diff = i + j - 1;
			for (int k = j; k < diff; k++)
				for (int t = 1; t <= 4; t++) {
					if (!cbn[j][k][t]) continue;
					for (int q = 1; q <= 4; q++) {
						if (!cbn[k + 1][diff][q]) continue;
						for (int o = 1; o <= 4; o++)
							if (cbn[j][k][t] && cbn[k + 1][diff][q] && ok[t][q][o])
								cbn[j][diff][o] = 1;
					}
				}
		}
	
	bool flg = 0;
	if (cbn[1][n][1]) { printf("W"); flg = 1; }
	if (cbn[1][n][2]) { printf("I"); flg = 1; }
	if (cbn[1][n][3]) { printf("N"); flg = 1; }
	if (cbn[1][n][4]) { printf("G"); flg = 1; }
	
	if (flg) printf("\n");
	else printf("The name is wrong!\n");
	return 0;
}
