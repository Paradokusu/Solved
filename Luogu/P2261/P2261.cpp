#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 n, k, ans;

int main() {
	scanf("%lld %lld", &n, &k);
	
	ans = n * k;
	for (i64 l = 1, r; l <= n; l = r + 1) {
		if (k / l != 0)
			r = min(k / (k / l), n);
		else
			r = n;
		
		ans -= (k / l) * (r - l + 1) * (l + r) / 2;
	}
	
	printf("%lld\n", ans);
	return 0;
}
