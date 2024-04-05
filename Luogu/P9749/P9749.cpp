#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, d;
int a[N], v[N];

i64 ans;
i64 sum[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> d;

	for (int i = 1; i < n; i++)
		std::cin >> v[i];

	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	i64 Min = a[1], k = 1;

	for (int i = 1; i < n; i++) {
		if (a[i] >= Min)
			sum[k] += v[i];
		else {
			k = i;
			Min = a[i];
			sum[i] += v[i];
		}
	}

	i64 cot = 0;

	for (int i = 1; i <= n; i++) {
		ans += std::ceil(sum[i] * 1.0 / d) * a[i];
		cot += std::ceil(sum[i] * 1.0 / d) * d - sum[i];

		if (cot >= d) {
			cot -= d;
			ans -= a[i];
		}
	}

	std::cout << ans << "\n";
	return 0;
}
