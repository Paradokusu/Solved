#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int cot[N];

void solve() {
	int n;
	std::cin >> n;
	
	memset(cot, 0, sizeof(cot));
	
	int ans = 0;
	
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		cot[in]++;
		
		if (cot[in] == 2)
			ans++;
	}
	
	std::cout << ans << "\n";
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
