#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr i64 inf = 1e14;

int n, top;
i64 ans, k, pw = 1;
i64 a[N], s[N], stc[N];

std::map<i64, int> Map;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = a[i] + s[i - 1];
	}
	
	for (int i = 0; i <= 60; i++) {
		if (std::abs(pw) > inf)
			break;
		
		stc[++top] = pw;
		pw *= k;
	}
	
	Map[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (k == 1)
			ans += Map[s[i] - 1];
		else if (k == -1)
			ans += Map[s[i] - 1] + Map[s[i] + 1];
		else {
			for (int siz = 1; siz <= top; siz++) {
				ans += Map[s[i] - stc[siz]];
			}
		}
		
		Map[s[i]]++;
	}
	
	std::cout << ans << "\n";
	return 0;
}
