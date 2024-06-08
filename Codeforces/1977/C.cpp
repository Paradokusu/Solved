#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2007;

int T, n, a[N];
i64 ans;

void calc(int x) {
	i64 res = 0, lcm = 1;
	for (int i = 1; i <= n; i++) {
		if (x % a[i] == 0) {
			res++;
			lcm = lcm * a[i] / __gcd(lcm, 1ll * a[i]);
		}
		if (a[i] == x) return;
	}
	
	if (lcm == x) ans = max(ans, res);
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	sort(a + 1, a + n + 1);
	bool flg = 0;
	for (int i = 1; i < n; i++) {
		if (__gcd(a[i], a[n]) != a[i]) {
			flg = 1;
			break;
		}
	}
	
	if (flg) {
		printf("%d\n", n);
		return;
	}
	
	ans = 0;
	for (int i = 1; i * i <= a[n]; i++) {
		if (a[n] % i == 0) {
			calc(i);
			calc(a[n] / i);
		}
	}
	
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
