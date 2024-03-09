#include <bits/stdc++.h>

constexpr int N = 507;
constexpr int inf = 2147483647;

int n, m, k, q, ans;
int a[N][N], mx[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m >> k >> q;
	memset(a, 0x3f, sizeof(a));
	
	for (int i = 1; i <= q; i++) {
		int x, y, t;
		std::cin >> x >> y >> t;
		a[x][y] = t;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - k + 1; j++)
			for (int ck = 0; ck < k; ck++)
				mx[i][j] = std::max(mx[i][j], a[i][j + ck]);
	}
	
	int ans = inf;
	
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= m - k + 1; j++) {
			int sum = 0;
			
			for (int ck = 0; ck < k; ck++)
				sum = std::max(sum, mx[i + ck][j]);
			
			ans = std::min(ans, sum);
		}
	}
	
	if (ans > 1e9)
		std::cout << "-1\n";
	else
		std::cout << ans << "\n";
	
	return 0;
}
