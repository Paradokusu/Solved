#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	i64 n, q;
	std::cin >> n >> q;
	std::vector<i64> P(n), T(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> P[i];
	}
	
	while (q--) {
		i64 k;
		std::cin >> k;
		
		for (int i = 0; i < n; i++)
			T[i] = P[i];
		
		i64 ans = 0;
		
		for (i64 i = 60; i >= 0; i--) {
			i64 sum = 0;
			
			for (i64 j = 0; j < n; j++) {
				if (T[j] & (1ll << i))
					continue;
				
				i64 p = (T[j] / (1ll << i)) * (1ll << i) + (1ll << i);
				p += ans ^ (p & ans);
				sum += p - T[j];
				
				if (sum > k) {
					break;
				}
			}
			
			if (sum > k) {
				continue;
			}
			
			for (i64 j = 0; j < n; j++) {
				if (T[j] & (1ll << i))
					continue;
				
				i64 p = (T[j] / (1ll << i)) * (1ll << i) + (1ll << i);
				p += ans ^ (p & ans);
				T[j] = p;
			}
			
			ans += (1ll << i);
			k -= sum;
		}
		
		std::cout << ans << "\n";
	}
	
	return 0;
}
