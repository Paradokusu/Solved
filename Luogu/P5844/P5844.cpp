#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

i64 r, l, b, ans;
i64 a[N], sum[N];

bool check(i64 x) {
	for (i64 i = 1; i <= r - x + 1; i++) {
		i64 _l = i, _r = i + x - 1, mid = (_l + _r) >> 1, pos = a[mid];
		i64 res = pos * (mid - _l) - (sum[mid - 1] - sum[_l - 1]) + (sum[_r] - sum[mid]) - pos * (_r - mid);
		if (res <= b) return 1;
	}
	return 0;
}

int main() {
	scanf("%lld %lld %lld", &r, &l, &b);
	for (i64 i = 1; i <= r; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	
	i64 _l = 1, _r = r + 1;
	while (_l < _r) {
		i64 mid = (_l + _r) >> 1;
		if (check(mid)) {
			_l = mid + 1;
			ans = std::max(ans, mid);
		} else
			_r = mid;
	}
	
	printf("%lld\n", ans);
	return 0;
}

