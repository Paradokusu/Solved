#include <bits/stdc++.h>

typedef long long i64;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 n, m;
	i64 sarray = 10;
	std::cin >> n >> m;
	std::vector<std::vector<i64>> a(n + 5, std::vector<i64>(m + 5));
	std::vector<i64> cnt(sarray + 5);

	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}

	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= m; j++) {
			ans += (cnt[a[i][j]] - 1);
			if (i - 1 >= 1) if (a[i - 1][j] == a[i][j]) ans--;
			if (i + 1 <= n) if (a[i + 1][j] == a[i][j]) ans--;
			if (j - 1 >= 1) if (a[i][j - 1] == a[i][j]) ans--;
			if (j + 1 <= m) if (a[i][j + 1] == a[i][j]) ans--;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
