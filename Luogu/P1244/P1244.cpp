#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> f(n + m + 1);
	
	f[0] = m + 1;
	int res = f[0] + m + 1;
	
	for (int i = 1; i <= n; i++) {
		f[i] = res;
		res += f[i];
	}
	
	std::cout << f[n] << "\n";
	
	return 0;
}
