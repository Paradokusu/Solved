#include <bits/stdc++.h>

constexpr int N = 50 + 7;
constexpr int MOD = 1000003;

int n, k;
int f[N][1 << 15], mtc[N][N];
char s[N << 1][N << 1];

void init() {
	memset(f, 0, sizeof(f));
	memset(mtc, 0, sizeof(mtc));
}

void solve() {
	init();
	
	std::cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		std::cin >> s[i];
	
	int len = strlen(s[1]);
	
	for (int i = 0; i < len; i++)
		for (char ch = 'a'; ch <= 'z'; ch++)
			for (int j = 1; j <= n; j++)
				if (s[j][i] == '?' || s[j][i] == ch)
					mtc[i][ch - 'a'] |= (1 << (j - 1));
	
	int cot = (1 << n) - 1;
	f[0][cot] = 1;
	
	for (int i = 0; i < len; i++)
		for (int j = 0; j <= cot; j++)
			if (f[i][j])
				for (char ch = 'a'; ch <= 'z'; ch++) {
					f[i + 1][mtc[i][ch - 'a'] & j] += f[i][j];
					f[i + 1][mtc[i][ch - 'a'] & j] %= MOD;
				}

	int ans = 0;

	for (int i = 0; i <= cot; i++) {
		int res = 0;
		
		for (int j = 1; j <= cot; j <<= 1)
			res += (bool) (i & j);
		
		if (res == k)
			(ans += f[len][i]) %= MOD;
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
