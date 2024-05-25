#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;

i64 n, tot, phi;
i64 tmp, ans;
i64 x[N];

int main() {
	scanf("%lld", &n);
	for (i64 i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			x[++tot] = i;
			if (i * i != n)
				x[++tot] = n / i;
		}
	}
	
	sort(x + 1, x + tot + 1);
	for (int i = 1; i <= tot; i++) {
		phi = tmp = x[i];
		for (int j = 2; j <= i && x[j] * x[j] <= tmp; j++) {	// 求 phi(d), 注意 x[1] = 1
			if (tmp % x[j] == 0) {
				phi = phi / x[j] * (x[j] - 1);
				while (tmp % x[j] == 0) tmp /= x[j];
			}
		}
		if (tmp != 1) phi = phi / tmp * (tmp - 1);
		ans += n / x[i] * phi;
	}
	
	printf("%lld\n", ans);
	return 0;
}
