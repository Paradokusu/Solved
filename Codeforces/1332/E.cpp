#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int p = 998244353;
constexpr int inv = 499122177;	// inv(p) (mod 2)

i64 n, m, l, r;

i64 expow(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
	}
	return res;
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &l, &r);
	if ((n & 1) && (m & 1)) printf("%lld\n", expow(r - l + 1, n * m));
	else {
		i64 a = r / 2 - (l - 1) / 2;
		i64 b = r - l + 1 - a;
		printf("%lld\n", (expow((a + b) % p, n * m) + expow((a - b + p) % p, n * m)) * inv % p);
	}
	return 0;
}
