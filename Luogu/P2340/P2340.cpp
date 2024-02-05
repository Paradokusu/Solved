#include <bits/stdc++.h>

using namespace std;

constexpr int N = 4e5;
constexpr int S = 407;

int n, ans;
int iq[S], eq[S], dp[(N << 1) + 7];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &iq[i], &eq[i]);
	memset(dp, -0x3f, sizeof(dp));
	
	dp[0 + N] = 0;
	for (int i = 1; i <= n; i++) {
		if (iq[i] > 0) {
			for (int j = N; j >= -N; j--) {
				if (-N <= j - iq[i] && j - iq[i] <= N)
					dp[j + N] = max(dp[j + N], dp[j - iq[i] + N] + eq[i]);
			}
		} else {
			for (int j = -N; j <= N; j++) {
				if (-N <= j - iq[i] && j - iq[i] <= N)
					dp[j + N] = max(dp[j + N], dp[j - iq[i] + N] + eq[i]);
			}
		}
	}
	
	for (int i = 0; i <= N; i++) {
		if (dp[i + N] >= 0)
			ans = max(i + dp[i + N], ans);
	}
	
	printf("%d\n", ans);
	return 0;
}
