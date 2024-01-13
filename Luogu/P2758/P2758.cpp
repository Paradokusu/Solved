#include <bits/stdc++.h>

constexpr int N = 2e3 + 7;

int n, m;
int f[N][N];	// 将 a 的前 i 个字符完全转化成 b 的前 j 个字符的最少操作次数
std::string a, b;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> a >> b;
	n = a.size(), m = b.size();
	for (int i = 1; i <= n; i++)
		f[i][0] = i;
	for (int i = 1; i <= m; i++)
		f[0][i] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = std::min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
	std::cout << f[n][m] << "\n";
	return 0;
}
