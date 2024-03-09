#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	i64 ans = 0, mxn = 0;
	
	for (int i = 1, inp; i <= n; i++) {
		std::cin >> inp;
		ans += inp;
		mxn = std::max(mxn, 1ll * inp);
	}
	
	n -= 1;
	
	if (ans % n == 0) {
		ans /= n;
	} else {
		ans = ans / n + 1;
	}
	
	if (ans < mxn)
		ans = mxn;
	
	std::cout << ans << "\n";
	return 0;
}
