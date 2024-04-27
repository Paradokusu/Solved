#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, m;
int b[N], c[N];
std::vector<int> p[N];

void solve() {
	std::cin >> n;
	
	for (int i = 1, x; i <= n; i++) {
		std::cin >> x;
		m = std::max(m, x);
		p[x + 1].push_back(i);
		b[i] = 1;
	}
	
	for (int i = 1; i <= m; i++) {
		c[i] = c[i - 1];
		
		for (auto x : p[i]) {
			c[i] += (b[x - 1] & b[x + 1]) - (!(b[x - 1] | b[x + 1]));
			b[x] = 0;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		long long ans = 0;
		
		for (int j = 1; j <= m; j += i)
			ans += c[j] + 1;
		
		std::cout << ans << " ";
	}
	
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	
	return 0;
}
