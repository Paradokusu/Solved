#include <bits/stdc++.h>

constexpr int N = 20;
constexpr int M = 2007;

int t, n, m;

struct node {
	int a[N], mx;
	
	void clear() {
		mx = 0;
	}
	
	void init() {
		for (int i = 0; i < n; i++)
			mx = std::max(mx, a[i]);
	}
	
	const bool operator < (const node &x) const {
		return mx > x.mx;
	}
} c[N << 8];

int w[1 << N];
int dp[N][1 << N];

void reset() {
	memset(dp, 0, sizeof dp);

	for (int i = 0; i < m; i++)
		c[i].clear();
}

void solve() {
	std::cin >> n >> m;
	reset();
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> c[j].a[i];
	
	for (int j = 0; j < m; j++)
		c[j].init();
	
	std::sort(c, c + m);
	
	for (int i = 0; i < std::min(n, m); i++) {
		for (int j = 0; j < (1 << n); j++) {
			w[j] = 0;
			
			for (int k = 0; k < n; k++) {
				int res = 0;
				
				for (int l = 0; l < n; l++)
					if ((1 << l) & j)
						res += c[i].a[(l + k) % n];
				
				w[j] = std::max(w[j], res);
			}
		}
		
		for (int j = 0; j < (1 << n); j++) {
			if (i == 0) {
				dp[i][j] = w[j];
				continue;
			}
			
			dp[i][j] = dp[i - 1][j];
			
			for (int k = j; k; k = (k - 1) & j)
				dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + w[k ^ j]);
		}
	}
	
	std::cout << dp[std::min(n, m) - 1][(1 << n) - 1] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
