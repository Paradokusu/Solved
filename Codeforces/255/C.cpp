#include <bits/stdc++.h>

using namespace std;

constexpr int N = 4007;

int n, tot, ans;
int a[N], dp[N][N];
unordered_map<int, int> mp;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!mp[a[i]]) {
			mp[a[i]] = ++tot;
		}
	}
	
	for (int i = 1; i <= n; i++)
		a[i] = mp[a[i]];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][a[j]] = dp[j][a[i]] + 1;
			ans = max(ans, dp[i][a[j]]);
		}
	}
	
	printf("%d\n", ans + 1);
	return 0;
}
