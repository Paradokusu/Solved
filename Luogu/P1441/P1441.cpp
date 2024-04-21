#include <bits/stdc++.h>

constexpr int N = 25;
constexpr int S = 2e3 + 7;

int n, m, ans;
int w[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		std::cin >> w[i];

	int len = (1 << n);
	
	for (int i = 0; i < len; i++) {
		if (__builtin_popcount(i) == n - m) {
			std::bitset<S> bs;
			bs[0] = 1;
			
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					bs |= (bs << w[j]);
			
			int cot = bs.count();
			ans = std::max(ans, cot);
		}
	}
	
	std::cout << ans - 1 << "\n";
	return 0;
}
