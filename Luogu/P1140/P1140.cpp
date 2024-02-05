#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;
const int d[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 5, -1, -2, -1, -3},
	{0, -1, 5, -3, -2, -4},
	{0, -2, -3, 5, -2, -2},
	{0, -1, -2, -2, 5, -1},
	{0, -3, -4, -2, -1, 0}
};

int a_len, b_len;
int a[N], b[N], dp[N][N];

void Exchange(char c, int pos, int *arr) {
	if (c == 'A') arr[pos] = 1;
	else if (c == 'C') arr[pos] = 2;
	else if (c == 'G') arr[pos] = 3;
	else if (c == 'T') arr[pos] = 4;
}

int main() {
	scanf("%d", &a_len);
	for (int i = 1; i <= a_len; i++) {
		char ch;
		scanf(" %c", &ch);
		Exchange(ch, i, a);
	}
	scanf("%d", &b_len);
	for (int i = 1; i <= b_len; i++) {
		char ch;
		scanf(" %c", &ch);
		Exchange(ch, i, b);
	}
	
	dp[0][0] = 0;
	for (int i = 1; i <= a_len; i++)
		dp[i][0] = dp[i - 1][0] + d[a[i]][5];
	for (int i = 1; i <= b_len; i++)
		dp[0][i] = dp[0][i - 1] + d[5][b[i]];
	
	for (int i = 1; i <= a_len; i++)
		for (int j = 1; j <= b_len; j++)
			dp[i][j] = max({dp[i - 1][j - 1] + d[a[i]][b[j]], dp[i - 1][j] + d[a[i]][5], dp[i][j - 1] + d[5][b[j]]});

	printf("%d\n", dp[a_len][b_len]);
	return 0;
}
