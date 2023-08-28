#include <bits/stdc++.h>

const int N = 150;

int dp[2][N + 5][N * N + 5];

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i + 1; j++)
			for (int k = 0; k <= j * (i + 1 - j); k++)
				dp[1][j][k] = n;
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= j * (i - j); k++) {
				dp[1][j + 1][k] = std::min(dp[1][j + 1][k], dp[0][j][k] + (s[i] != '0'));
				dp[1][j][k + j] = std::min(dp[1][j][k + j], dp[0][j][k] + (s[i] != '1'));
			}
		}
		std::swap(dp[0], dp[1]);
	}
	int cnt0 = std::count(s.begin(), s.end(), '0');
	int x = (cnt0 * (n - cnt0)) / 2;
	std::cout << dp[0][cnt0][x] / 2 << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
