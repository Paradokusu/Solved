#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, b, sp;
i64 lsum, rsum, ans;
int a[N];

std::unordered_map<int, int> mp;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> b;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		
		if (a[i] == b)
			sp = i;
	}
	
	/* 使用前缀和思想将数替换成 1 和 -1 */
	
	for (int i = sp; i <= n; i++) {
		if (a[i] > b)
			rsum++;
		
		if (a[i] < b)
			rsum--;
		
		mp[rsum]++;
	}
	
	for (int i = sp; i >= 1; i--) {
		if (a[i] > b)
			lsum++;
		
		if (a[i] < b)
			lsum--;
		
		ans += mp[0 - lsum];
	}
	
	std::cout << ans << "\n";
	return 0;
}
