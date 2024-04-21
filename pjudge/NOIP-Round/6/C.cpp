#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n;
i64 ans;
i64 a[N], dp[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++)
			dp[i] = std::max(dp[i], dp[j] + (a[j] & a[i]));
		
		ans = std::max(ans, dp[i]);
	}
	
	std::cout << ans << "\n";
	return 0;
}
