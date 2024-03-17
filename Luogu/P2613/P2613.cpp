#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 MOD = 19260817;

i64 n, m;

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 % MOD + ch - '0' % MOD;
	return sum * fl % MOD;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

i64 expow(i64 a, i64 b, const i64 p) {
	i64 res = 1 % p;
	
	for (; b; b >>= 1) {
		if (b & 1)
			res = 1ll * res * a % MOD;

		a = 1ll * a * a % MOD;
	}
	
	return 1ll * res % MOD * p % MOD;
}

int main() {
	n = read<i64>(), m = read<i64>();
	
	if (m) {
		write<i64>(expow(m, MOD - 2, n));
		puts("");
	} else {
		puts("Angry!");
	}
	
	return 0;
}
