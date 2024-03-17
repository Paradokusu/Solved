#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 n, k;

i64 lcm(i64 a, i64 b) {
	return a / __gcd(a, b) * b;
}

int main() {
	scanf("%lld %lld", &n, &k);
	
	i64 t = 1;
	for (i64 i = 1, in; i <= n; i++) {
		scanf("%lld", &in);
		if (!t) continue;
		t = lcm(t, in);
		t %= k;
	}
	
	printf("%s\n", (!t ? "Yes" : "No"));
	return 0;
}
