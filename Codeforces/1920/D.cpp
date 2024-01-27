#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 2e18;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> lst(n + 1);
	std::vector<i64> f(n + 1);
	std::vector<int> pos;

	for (int i = 1, flg = 1; i <= n; i++) {
		int a, v;
		std::cin >> a >> v;

		if (a == 1) {
			lst[i] = v;
			f[i] = f[i - 1] + 1;
		} else {
			lst[i] = lst[i - 1];
			f[i] = ((v + 1) > inf / f[i - 1]) ? (i64) 2e18 : f[i - 1] * (v + 1);

			if (flg) {
				pos.emplace_back(i);
			}
		}

		if (f[i] == inf)
			flg = false;
	}

	while (q--) {
		i64 k;
		std::cin >> k;

		for (int i = pos.size() - 1; ~i; i--) {
			int idx = pos[i];

			if (f[idx] > k && f[idx - 1] < k) {
				if (k % f[idx - 1] == 0) {
					k = f[idx - 1];
					break;
				}
				k %= f[idx - 1];
			}
		}

		std::cout << lst[std::lower_bound(f.begin() + 1, f.end(), k) - f.begin()] << " ";
		if (q == 0) {
			std::cout << "\n";
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
