#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr i64 inf = 1e18;

int n, k;
i64 l, r, ans;
int a[N];

int check(i64 x) {
	i64 res = 0, len = 0;

	for (int i = 1; i <= n; i++) {
		res += a[i];

		if (res < 0)
			res = 0;

		if (res >= x) {
			res = 0;
			len++;
		}
	}

	return len;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;

	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	l = 1, r = inf, ans = inf;

	while (l <= r) {
		i64 mid = (l + r) >> 1;

		if (check(mid) > k)
			l = mid + 1;
		else if (check(mid) < k)
			r = mid - 1;
		else {
			ans = mid;
			r = mid - 1;
		}
	}

	if (ans != inf)
		std::cout << ans << " ";
	else {
		std::cout << "-1\n";
		return 0;
	}

	l = 1, r = inf, ans = inf;

	while (l <= r) {
		i64 mid = (l + r) >> 1;

		if (check(mid) > k)
			l = mid + 1;
		else if (check(mid) < k)
			r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}

	std::cout << ans << "\n";

	return 0;
}
