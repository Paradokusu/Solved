#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n;
int cot[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1, inp; i <= n; i++) {
		std::cin >> inp;
		
		for (int j = 1; j * j <= inp; j++) {
			if (inp % j == 0) {
				cot[j]++;
				
				if (j * j != inp) {
					cot[inp / j]++;
				}
			}
		}
	}
	
	int ans = 1;
	
	for (int i = 2; i < N; i++) {
		ans = std::max(ans, cot[i]);
	}
	
	std::cout << ans << "\n";
	return 0;
}
