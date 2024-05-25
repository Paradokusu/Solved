#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 20;

int n, r;
i64 ans = 1, S[N][N];

int main() {
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= r; i++)
		ans *= i;

	S[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = S[i - 1][j - 1] + j * S[i - 1][j];
	ans *= S[n][r];
	
	printf("%lld\n", ans);
	return 0;
}
