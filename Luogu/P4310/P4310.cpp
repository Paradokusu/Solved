#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, ans;
int dp[N];

int main() {
	scanf("%d", &n);
	for (int t = 1, in; t <= n; t++) {
		int k = 1;
		scanf("%d", &in);
		for (int i = 0; i <= 30; i++) {
			if ((1 << i) & in)
				k = max(dp[i] + 1, k);
		}
		for (int i = 0; i <= 30; i++) {
			if ((1 << i) & in)
				dp[i] = max(dp[i], k);
		}
		ans = max(ans, k);
	}
	printf("%d\n", ans);
	return 0;
}
