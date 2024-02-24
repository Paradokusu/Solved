#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);	

	int W, n;
	std::cin >> W >> n;
	const int N = (1 << n) - 1;

	std::vector<int> ts(N + 1), tw(N + 1);

	for (int j = 0; j < n; j++) {
		int t, w;
		std::cin >> t >> w;

		for (int i = 0; i <= N; i++) {
			if (i & (1 << j)) {
				ts[i] = std::max(ts[i], t);
				tw[i] += w;
			}
		}
	}

	std::vector<int> dp(N + 1, std::numeric_limits<int>::max() / 2);

	for (int i = 0; i <= N; i++) {
		if (tw[i] <= W)
			dp[i] = ts[i];

		for (int j = i; j; j = i & (j - 1))
			if (tw[i ^ j] <= W)
				dp[i] = std::min(dp[i], dp[j] + ts[i ^ j]);
	}

	std::cout << dp[N] << "\n";
	return 0;
}
