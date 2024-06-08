#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 expow(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a;
		a = 1ll * a * a;
	}
	return res;
}

void solve() {
	i64 x;
	scanf("%lld", &x);
	
	int a[35] = {0};
	
	for (int i = 0; i < 30; i++) {
		if (1ll & (x >> i)) {
			if (a[i]) {
				a[i + 1] = 1;
				a[i] = 0;
			} else if (i > 0) {
				if (a[i - 1] == 1) {
					a[i + 1] = 1;
					a[i - 1] = -1;
				} else {
					a[i] = 1;
				}
			} else if (i == 0) {
				a[i] = 1;
			}
		}
	}
	
	printf("31\n");
	for (int i = 0; i < 31; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

