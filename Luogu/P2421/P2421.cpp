#include <bits/stdc++.h>

constexpr int N = 20;

int n, mx = 1;
int s[N], p[N], l[N];

int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	
	return d;
}

bool check(int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = p[i] - p[j], b = m;
			int x, y, c = s[j] - s[i];
			int d = exgcd(a, b, x, y);
			
			if (c % d) {
				continue;
			}
			
			a /= d, b /= d, c /= d;
			b = std::abs(b);
			x = (x * c % b + b) % b;
			
			if (x <= l[i] && x <= l[j]) {
				return 0;
			}
		}
	}
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i] >> p[i] >> l[i];
		mx = std::max(mx, s[i]);
	}
	
	for (int i = mx; ; i++) {
		if (check(i)) {
			std::cout << i << "\n";
			break;
		}
	}
	
	return 0;
}
