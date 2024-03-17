#include <bits/stdc++.h>

constexpr int N = 507;

int n;
int a[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			std::cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		std::sort(a[i] + 1, a[i] + n + 1);
		ans = ans > a[i][n - 1] ? ans : a[i][n - 1];
	}
	
	std::cout << "1\n" << ans << "\n";
	return 0;
}
