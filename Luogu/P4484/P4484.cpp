#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

constexpr int N = 30;
constexpr int MOD = 998244353;

int n;
i64 ans, a[N];

i64 calcf(i64 t) {
	i128 ans = 1;

	for (int i = 1; i <= n; i++)
		ans *= i;

	for (i64 i = 0; i < t; i++) {
		for (int j = t - 1, k = 0; k < a[i]; k++) {
			while (a[j] <= k)
				j--;

			ans /= a[i] - k + j - i;
		}
	}

	ans %= MOD;
	return ans * ans % MOD;
}

void dfs(i64 i, i64 m) {
	if (!m)
		(ans += calcf(i) * a[0]) %= MOD;
	else if (i64 &x = a[i] = i ? std::min(a[i - 1], m) : m)
		while (x) {
			dfs(i + 1, m - x);
			x--;
		}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;

	dfs(0, n);

	for (int i = 1; i <= n; ans /= i++)
		while (ans % i)
			ans += MOD;

	std::cout << ans << "\n";
	return 0;
}
