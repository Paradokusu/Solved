#include <bits/stdc++.h>

constexpr int N = 4e5 + 7;
constexpr int inf = 2147483647;

int n, k;
int a[N], s[N], dp[N];
int val[N], st[N], pos[N << 1];
bool mk[N];

bool check(int x) {
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		
		if (a[i] >= x)
			tmp = 1;
		else
			tmp = -1;
		
		s[i] = s[i - 1] + tmp;
	}
	
	memset(pos, 0, sizeof(pos));
	memset(mk, 0, sizeof(mk));
	
	for (int i = 1; i <= n; i++)
		dp[i] = i - 1;
	
	for (int i = 1; i <= n; i++)
		pos[s[i] + n] = i;
	
	for (int i = n << 1; i >= 0; i--)
		pos[i] = std::max(pos[i], pos[i + 1]);
	
	for (int i = 1, lim = 1e9; i <=  n; i++)
		if (s[i - 1] < lim) {
			mk[i] = 1;
			lim = s[i - 1];
		}
	
	int l, r;
	
	for (int z = 1; z <= k && z <= 25; z++) {
		l = 1, r = 0;
		
		for (int i = n; i >= 1; i--) {
			if (mk[i]) {
				int v = (dp[i] - i + 1) - (s[dp[i]] - s[i - 1]);
				
				while (l <= r && val[r] < v)
					r--;
				
				++r;
				val[r] = v;
				st[r] = dp[i];
				
				while (l <= r) {
					int p = pos[std::max(0, s[i - 1] + 1 - val[l] + n)];
					
					if (p >= st[l]) {
						dp[i] = p;
						break;
					}
					
					l++;
				}
			}
		}
		
		if (dp[1] == n)
			return 1;
	}
	
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	if (k == 0) {
		int ans = inf;
		
		for (int i = 1; i <= n; i++)
			ans = std::min(ans, a[i]);
		
		std::cout << ans << "\n";
		exit(0);
	}
	
	int L = 0, R = 1e9;
	
	while (L < R) {
		int mid = (L + R + 1) >> 1;
		
		if (check(mid))
			L = mid;
		else
			R = mid - 1;
	}
	
	std::cout << L << "\n";
	return 0;
}
