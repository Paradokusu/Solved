#include <bits/stdc++.h>

using namespace std;

int a, m, n;
int phi = 1;
int bm, flg;

int expow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % m;
		a = 1ll * a * a % m;
	}
	return res;
}

int main() {
	scanf("%d %d", &a, &m);
	a %= m;
	
	n = m;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		phi *= i - 1;
		n /= i;
		while (n % i == 0) {
			phi *= i;
			n /= i;
		}
	}
	if (n > 1) phi *= n - 1;
	
	char ch;
	while ((ch = getchar()) < '0' || ch > '9');
	while (bm = bm * 10ll + (ch ^ '0'), (ch = getchar()) >= '0' && ch <= '9')
		if (bm >= phi)
			flg = 1, bm %= phi;
	
	if (bm >= phi) flg = 1, bm %= phi;
	if (flg) bm += phi;

	printf("%d\n", expow(a, bm));
	return 0;
}
