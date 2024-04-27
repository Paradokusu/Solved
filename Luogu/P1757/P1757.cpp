#include <bits/stdc++.h>

constexpr int N = 1007;

int n, m, t;
int b[N], w[N], z[N];
int f[N];
int g[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1, x; i <= m; i++) {
		std::cin >> w[i] >> z[i] >> x;
		t = std::max(t, x);
		b[x]++;
		g[x][b[x]] = i;
	}
	
	for (int i = 1; i <= t; i++) {
		for (int j = n; j >= 0; j--) {
			for (int k = 1; k <= b[i]; k++) {
				if (j >= w[g[i][k]]) {
					f[j] = std::max(f[j], f[j - w[g[i][k]]] + z[g[i][k]]);
				}
			}
		}
	}
	
	std::cout << f[n] << "\n";
	return 0;
}
