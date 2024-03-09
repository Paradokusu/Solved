#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int n, m, p, q;
	std::cin >> n >> m >> p >> q;
	std::vector<int> vis(n + 1), clr(n + 1);
	
	for (int i = m; i >= 1; i--) {
		int a = (i * p + q) % n + 1;
		int b = (i * q + p) % n + 1;
		
		int c = std::min(a, b);
		int d = std::max(a, b);
		
		for (int j = c; j <= d; j++) {
			if (vis[j])
				break;
			else {
				vis[j] = 1;
				clr[j] = i;
			}
		}
		
		for (int j = d; j >= c; j--) {
			if (vis[j])
				break;
			else {
				vis[j] = 1;
				clr[j] = i;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << clr[i] << "\n";
	}
	
	return 0;
}
