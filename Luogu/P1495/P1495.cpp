#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 17;

int n;
i64 x, y, MM;
i64 m[N], a[N], t[N], M[N];

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	
	i64 d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	
	return d;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	MM = 1, x = 0;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> m[i] >> a[i];
		MM *= m[i];
	}
	
	for (int i = 1; i <= n; i++) {
		M[i] = MM / m[i];
		exgcd(M[i], m[i], t[i], y);
		t[i] = (m[i] + t[i] % m[i]) % m[i];
		
		for (int j = 1; j <= a[i]; j++) {
			x = (x + M[i] * t[i]) % MM;
		}
	}
	
	std::cout << x << "\n";
	return 0;
}
