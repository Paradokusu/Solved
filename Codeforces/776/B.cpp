#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n;
std::bitset<N> vis;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	vis[0] = vis[1] = 1;
	
	for (int i = 2; i * i <= n + 1; i++) {
		if (!vis[i]) {
			for (int j = i * 2; j <= n + 1; j += i) {
				vis[j] = 1;
			}
		}
	}
	
	if (n < 3) {
		std::cout << "1\n";
	} else {
		std::cout << "2\n";
	}
	
	for (int i = 2; i <= n + 1; i++) {
		std::cout << vis[i] + 1 << " ";
	}
	
	std::cout << "\n";
	return 0;
}
