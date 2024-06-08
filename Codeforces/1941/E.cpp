#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 107;
constexpr int M = 2e5 + 7;

int T;
int n, m, k, d;
int a[N][M];
i64 dp[M], sum[M];

void solve() {
	scanf("%d %d %d %d", &n, &m, &k, &d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
	
	for (int i = 1; i <= n; i++) {
		deque<i64> dq;
		dp[1] = a[i][1] + 1;
		dq.push_back(1);
		
		for (int j = 2; j <= m; j++) {
			if (!dq.empty() && j - dq.front() - 1 > d) dq.pop_front();
			dp[j] = dp[dq.front()] + a[i][j] + 1;
			while (!dq.empty() && dp[dq.back()] > dp[j]) dq.pop_back();
			dq.push_back(j);
		}
		sum[i] = sum[i - 1] + dp[m];
	}
	
	i64 ans = sum[k];
	for (int i = k + 1; i <= n; i++)
		ans = min(ans, sum[i] - sum[i - k]);
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

