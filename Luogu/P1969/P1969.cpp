#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<i64> a(n + 1);
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	i64 ans = a[1];
	
	for (int i = 2; i <= n; i++)
		if (a[i] > a[i - 1])
			ans += a[i] - a[i - 1];
	
	std::cout << ans << "\n";
	return 0;
}
