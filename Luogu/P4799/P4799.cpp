#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1 << 20;

i64 n, m, mid, cotA, cotB, ans;
i64 w[N], sumA[N], sumB[N];

void dfs(int l, int r, i64 val, i64 a[], i64 &cot) {
	if (val > m)
		return;

	if (l > r) {
		a[++cot] = val;
		return;
	}

	dfs(l + 1, r, val + w[l], a, cot);
	dfs(l + 1, r, val, a, cot);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}

	mid = n / 2;

	dfs(1, mid, 0, sumA, cotA);
	dfs(mid + 1, n, 0, sumB, cotB);

	std::sort(sumA + 1, sumA + cotA + 1);

	for (int i = 1; i <= cotB; i++)
		ans += std::upper_bound(sumA + 1, sumA + cotA + 1, m - sumB[i]) - sumA - 1;

	std::cout << ans << "\n";
	return 0;
}
