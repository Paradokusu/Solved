#include <bits/stdc++.h>

constexpr int N = 4e4 + 7;

int n, ans;
int prime[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	std::iota(prime + 1, prime + n + 1, 1);
	
	for (int i = 2; i <= n; i++) {
		if (prime[i] == i) {
			for (int j = i; j <= n; j += i) {
				prime[j] = prime[j] * (i - 1) / i;
				// if (i % prime[j] == 0) break;
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		ans += prime[i];
	}
	
	if (n == 1) {
		std::cout << "0\n";
	} else {
		std::cout << (ans << 1 | 1) << "\n";
	}
	
	return 0;
}
