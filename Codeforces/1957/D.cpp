#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int S = 30;

int n;
i64 ans;
int a[N];
int pre[S][N][2], suf[S][N][2];

void init() {
	ans = 0;
	
	for (int i = 0; i < S; i++) {
		suf[i][n + 1][0] = 0;
		suf[i][n + 1][1] = 0;
	}
}

void solve() {
	std::cin >> n;
	init();
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	for (int i = 0; i < S; i++) {
		for (int j = 1; j <= n; j++) {
			int t = !(!(a[j] & (1 << i)));
			
			for (int k = 0; k < 2; k++)
				pre[i][j][k] = (t == k) + pre[i][j - 1][k ^ t];
		}
		
		for (int j = n; j >= 1; j--) {
			int t = !(!(a[j] & (1 << i)));
			
			for (int k = 0; k < 2; k++)
				suf[i][j][k] = (t == k) + suf[i][j + 1][k ^ t];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int t = S + 1 - __builtin_clz(a[i]);
		ans += 1ll * pre[t][i - 1][1] * (1 + suf[t][i + 1][0]);
		ans += 1ll * (1 + pre[t][i - 1][0]) * suf[t][i + 1][1];
	}
	
	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
