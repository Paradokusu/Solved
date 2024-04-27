#include <bits/stdc++.h>

constexpr int N = 3e4 + 7;

int n, m;
int v[N], w[N], f[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		std::cin >> v[i] >> w[i];
		w[i] *= v[i];
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			if (j >= v[i]) {
				f[j] = std::max(f[j], f[j - v[i]] + w[i]);
			}
		}
	}
	
	std::cout << f[n] << "\n";
	return 0;
}
