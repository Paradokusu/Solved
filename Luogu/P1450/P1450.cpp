#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

i64 c1, c2, c3, c4, qrs;
i64 dp[N + 5];

i64 fg(i64 x) {
	if (x < 0)
		return 0;
	
	return dp[x];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> c1 >> c2 >> c3 >> c4 >> qrs;
	dp[0] = 1;
	
	for (i64 i = c1; i <= N; i++)
		dp[i] += dp[i - c1];
	
	for (i64 i = c2; i <= N; i++)
		dp[i] += dp[i - c2];
	
	for (i64 i = c3; i <= N; i++)
		dp[i] += dp[i - c3];
	
	for (i64 i = c4; i <= N; i++)
		dp[i] += dp[i - c4];
	
	while (qrs--) {
		i64 d1, d2, d3, d4, s;
		std::cin >> d1 >> d2 >> d3 >> d4 >> s;
		d1 = (d1 + 1) * c1;
		d2 = (d2 + 1) * c2;
		d3 = (d3 + 1) * c3;
		d4 = (d4 + 1) * c4;
		
		std::cout << fg(s) - fg(s - d1) - fg(s - d2) - fg(s - d3) - fg(s - d4) +
			fg(s - d1 - d2) + fg(s - d1 - d3) + fg(s - d1 - d4) +
			fg(s - d2 - d3) + fg(s - d2 - d4) + fg(s - d3 - d4) -
			fg(s - d1 - d2 - d3) - fg(s - d1 - d2 - d4) -
			fg(s - d1 - d3 - d4) - fg(s - d2 - d3 - d4) +
			fg(s - d1 - d2 - d3 - d4) << "\n";
	}
	
	return 0;
}
