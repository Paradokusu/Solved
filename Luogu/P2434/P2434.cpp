#include <bits/stdc++.h>

constexpr int N = 5e4 + 7;

struct line {
	int l, r;
} a[N];

int n;

std::vector<std::pair<int, int>> ans;

bool cmp(const line &a, const line &b) {
	if (a.r == b.r)
		return a.l> b.l;
	
	return a.r > b.r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].l >> a[i].r;
	
	std::sort(a + 1, a + n + 1, cmp);
	
	int L = a[1].l, R = a[1].r;
	
	for (int i = 2; i <= n; i++) {
		if (a[i].r < L) {
			ans.push_back({L, R});
			L = a[i].l, R = a[i].r;
		} else {
			L = std::min(L, a[i].l);
		}
	}
	
	ans.push_back({L, R});
	std::sort(ans.begin(), ans.end());
	
	for (size_t i = 0; i < ans.size(); i++)
		std::cout << ans[i].first << " " << ans[i].second << "\n";
	
	return 0;
}
