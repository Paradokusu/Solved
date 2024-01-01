#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;

	std::vector<std::vector<i64>> max0pref(n + 1, std::vector<i64>(n + 1));
	std::vector<std::vector<i64>> max0suf(n + 1, std::vector<i64>(n + 1));

	for (int l = 0; l < n; l++) {
		int cnt1 = 0;
		for (int r = l + 1; r <= n; r++) {
			cnt1 += s[r - 1] == '1';
			max0pref[r][cnt1] = std::max(max0pref[r][cnt1], 1ll * r - l);
			max0suf[l][cnt1] = std::max(max0suf[l][cnt1], 1ll * r - l);
		}
	}

	for (int r = 0; r <= n; r++) {
		for (int cnt = 0; cnt <= n; cnt++) {
			if (r) max0pref[r][cnt] = std::max(max0pref[r][cnt], max0pref[r - 1][cnt]);
			if (cnt) max0pref[r][cnt] = std::max(max0pref[r][cnt], max0pref[r][cnt - 1]);
		}
	}

	for (int l = n; l >= 0; l--) {
		for (int cnt = 0; cnt <= n; cnt++) {
			if (l + 1 <= n) max0suf[l][cnt] = std::max(max0suf[l][cnt], max0suf[l + 1][cnt]);
			if (cnt) max0suf[l][cnt] = std::max(max0suf[l][cnt], max0suf[l][cnt - 1]);
		}
	}

	std::vector<i64> max0by1(n + 1, -inf);

	for (int l = 0; l < n; l++) {
		int cnt0 = 0;
		for (int r = l; r <= n; r++) {
			if (r > l) cnt0 += s[r - 1] == '0';
			if (cnt0 > k) break;
			max0by1[r - l] = std::max(max0by1[r - l], max0pref[l][k - cnt0]);
			max0by1[r - l] = std::max(max0by1[r - l], max0suf[r][k - cnt0]);
		}
	}

	std::vector<i64> ans(n + 1, -inf);

	for (int i = 0; i <= n; i++) {
		for (int a = 1; a <= n; a++)
			ans[a] = std::max(ans[a], i + max0by1[i] * a);
	}

	for (int i = 1; i <= n; i++)
		std::cout << ans[i] << " ";
	std::cout << "\n";
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
