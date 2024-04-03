#include <bits/stdc++.h>

using u64 = unsigned long long;

constexpr int N = 507;

int p;

u64 a[N] = {1};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> p;
	std::cout << (int) (p * std::log10(2)) + 1 << "\n";
	
	for (; p > 0; p -= 60) {
		u64 fwd = 0;
		
		for (int i = 0; i < 500; i++) {
			if (p > 60)
				a[i] <<= 60;	// 9 * (2 ^ 60) 不会溢出
			else
				a[i] <<= p;
			
			a[i] += fwd;
			fwd = a[i] / 10;
			a[i] %= 10;
		}
	}
	
	a[0] -= 1;
	
	for (int i = 499; i >= 0; i--) {
		std::cout << char(a[i] + '0');
		
		if (i % 50 == 0)
			std::cout << "\n";
	}
	
	return 0;
}
