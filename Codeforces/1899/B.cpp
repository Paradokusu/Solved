#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 5e4 + 7;
constexpr i64 inf = LLONG_MAX;

int n;
i64 a[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	
	i64 ans = -inf;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			i64 Min = inf, Max = -inf;
			for (int j = i; j <= n; j += i) {
				i64 diff = a[j] - a[j - i];
				Max = max(diff, Max);
				Min = min(diff, Min);
			}
			ans = max(ans, Max - Min);
		}
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
