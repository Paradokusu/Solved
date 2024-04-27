#include <bits/stdc++.h>

constexpr int MOD = 998244353;

int modMul(int x, int y) {
	return 1ll * x * y % MOD;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int sum = std::accumulate(a.begin(), a.end(), 0);
	
	std::vector<int> f(sum + 1);
	f[0] = 1;
	
	for (int i = 0; i < n; i++)
		for (int j = sum - a[i]; j >= 0; j--)
			f[j + a[i]] = (f[j + a[i]] + f[j]) % MOD;
	
	int ans = 0;
	
	for (int j = 0; j <= sum; j++)
		ans = (ans + modMul((j + 1) / 2, f[j])) % MOD;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < a[i]; j++)
			ans = (ans + modMul(a[i] - (a[i] + j + 1) / 2, f[j])) % MOD;
	
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	
	return 0;
}
