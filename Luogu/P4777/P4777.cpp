#include <bits/stdc++.h>

using namespace std;
using i128 = __int128;

int n;
i128 x, y, d;
i128 a, b, A, B;

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

i128 lcm(i128 a, i128 b) {
	return a / __gcd(a, b) * b;
}

void exgcd(i128 &x, i128 &y, i128 a, i128 b) {
	if (!b) {
		d = a, x = 1, y = 0;
	} else {
		exgcd(y, x, b, a % b);
		y -= a / b * x;
	}
}

void merge() {
	exgcd(x, y, a, A);
	i128 c = B - b;
	
	if (c % d) {
		puts("-1");
		exit(0);
	}
	
	x = x * c / d % (A / d);
	if (x < 0) x += A / d;
	
	i128 mod = lcm(a, A);
	b = (a * x + b) % mod;
	if (b < 0) b += mod;
	a = mod;
}

int main() {
	n = read<int>();
	for (int i = 1; i <= n; i++) {
		i128 ina = read<i128>(), inb = read<i128>();
		A = ina, B = inb;
		
		if (i > 1) {
			merge();
		} else {
			a = A;
			b = B;
		}
	}
	write<i128>(b % a);
	puts("");
	return 0;
}
