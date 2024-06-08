#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 a, b, c, p;

int main() {
	scanf("%lld %lld", &a, &b);
	if (a % 2 && b % 2) {
		printf("0-11-0");
		a += 11, b += 11, p = 2;
		while (((a - p) >> 1) % 10 == 0 || ((b - p) >> 1) % 10 == 0)
			p += 2;
		printf("+%lld+0", p);
		a -= p, b -= p;
		if (a < 0) printf("%lld%lld+", a >> 1, a >> 1);
		else printf("+%lld+%lld-", a >> 1, a >> 1);
		printf("0");
		b >>= 1;
		do {
			c = c * 10 + b % 10;
			b /= 10;
		} while (b);
		b = c;
		if (b < 0) printf("+%lld%lld-", -b, b);
		else printf("-%lld+%lld+", b, b);
		printf("0");
	} else if (a % 2) {
		printf("0-21-0");
		a += 21, b += 12, p = 2;
		while (((a - p) >> 1) % 10 == 0 || ((b - p) >> 1) % 10 == 0)
			p += 2;
		printf("+%lld+0", p);
		a -= p, b -= p;
		if (a < 0) printf("%lld%lld+", a >> 1, a >> 1);
		else printf("+%lld+%lld-", a >> 1, a >> 1);
		printf("0");
		b >>= 1;
		do {
			c = c * 10 + b % 10;
			b /= 10;
		} while (b);
		b = c;
		if (b < 0) printf("+%lld%lld-", -b, b);
		else printf("-%lld+%lld+", b, b);
		printf("0");
	} else if (b % 2) {
		printf("0-12-0");
		a += 12, b += 21, p = 2;
		while (((a - p) >> 1) % 10 == 0 || ((b - p) >> 1) % 10 == 0)
			p += 2;
		printf("+%lld+0", p);
		a -= p, b -= p;
		if (a < 0) printf("%lld%lld+", a >> 1, a >> 1);
		else printf("+%lld+%lld-", a >> 1, a >> 1);
		printf("0");
		b >>= 1;
		do {
			c = c * 10 + b % 10;
			b /= 10;
		} while (b);
		b = c;
		if (b < 0) printf("+%lld%lld-", -b, b);
		else printf("-%lld+%lld+", b, b);
		printf("0");
	} else {
		printf("0");
		p = 2;
		while (((a - p) >> 1) % 10 == 0 || ((b - p) >> 1) % 10 == 0)
			p += 2;
		printf("+%lld+0", p);
		a -= p, b -= p;
		if (a < 0) printf("%lld%lld+", a >> 1, a >> 1);
		else printf("+%lld+%lld-", a >> 1, a >> 1);
		printf("0");
		b >>= 1;
		do {
			c = c * 10 + b % 10;
			b /= 10;
		} while (b);
		b = c;
		if (b < 0) printf("+%lld%lld-", -b, b);
		else printf("-%lld+%lld+", b, b);
		printf("0");
	}
	return 0;
}
