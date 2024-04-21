#include <bits/stdc++.h>

constexpr int N = 20;
constexpr double eps = 1e-8;

int t, n, m;
int dp[1 << N], lbit[1 << N], lns[N][N];
double x[N], y[N];

void Pre() {
	for (int i = 0; i < (1 << 18); i++) {
		int j = 1;
		
		for (; j <= 18 && (i & (1 << (j - 1))); j++);
		
		lbit[i] = j;
	}
}

void Clear() {
	memset(lns, 0, sizeof(lns));
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
}

void Calc(double &x, double &y, double a1, double b1, double c1, double a2, double b2, double c2) {
	y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
	x = (c1 - b1 * y) / a1;
}

void solve() {
	Clear();

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> x[i] >> y[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (std::fabs(x[i] - x[j]) < eps)
				continue;
			
			double a, b;
			Calc(a, b, x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
			
			if (a > -eps)
				continue;
			
			for (int k = 1; k <= n; k++)
				if (std::fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps)
					lns[i][j] |= (1 << (k - 1));
		}
	}
	
	for (int i = 0; i < (1 << n); i++) {
		int j = lbit[i];
		dp[i | (1 << (j - 1))] = std::min(dp[i | (1 << (j - 1))], dp[i] + 1);
		
		for (int k = 1; k <= n; k++)
			dp[i | lns[j][k]] = std::min(dp[i | lns[j][k]], dp[i] + 1);
	}
	
	std::cout << dp[(1 << n) - 1] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	Pre();
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
