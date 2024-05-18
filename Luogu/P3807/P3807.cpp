#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int T;
i64 n, m, p;
i64 a[N];

void init() {
    const i64 mod = p;
    a[0] = 1;
    for (int i = 1; i <= mod; i++)
        a[i] = (1ll * a[i - 1] * i) % mod;
}

i64 expow(i64 a, i64 b, const i64 p) {
	i64 res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
	}
	return res;
}

i64 C(i64 n, i64 m) {
    if (m > n) return 0;
	return ((a[n] * expow(a[m], p - 2, p)) % p * expow(a[n - m], p - 2, p) % p);	// a[i] = i! % p
}

i64 Lucas(i64 n, i64 m) {
    if (!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &n, &m, &p);
        init();
        printf("%lld\n", Lucas(n + m, m));
    }
    return 0;
}
