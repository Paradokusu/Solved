#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 7;
constexpr int MOD = 1e9 + 7;

int n;
int l[N], r[N];

i64 ans;
i64 a[N], range[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> range[i];
		l[i] = r[i] = i;
	}
	
	for (int i = 2; i <= n; i++) {
		while (l[i] > 1 && a[i] - a[l[i] - 1] <= range[i]) {
			range[i] = std::max(range[i], range[l[i] - 1] - (a[i] - a[l[i] - 1]));
			l[i] = l[l[i] - 1];
		}
	}
	
	for (int i = n - 1; i >= 1; i--) {
		while (r[i] < n && a[r[i] + 1] - a[i] <= range[i]) {
			l[i] = std::min(l[i], l[r[i] + 1]);
			r[i] = r[r[i] + 1];
		}
	}
	
	for (int i = 1; i <= n; i++)
		ans = (ans + 1ll * i * (r[i] - l[i] + 1)) % MOD;
	
	std::cout << ans << "\n";
	return 0;
}
