#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	i64 t, n, m, p;
	std::cin >> t >> n >> m >> p;
	i64 a = 1;
	n = n + 1 - m;
	
	while (m--) {
		a = 1ll * a * n % p;
		n--;
	}
	
	std::cout << a << "\n";
	return 0;
}
