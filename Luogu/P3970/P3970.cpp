#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

int n, tot;
int a[N], lsh[N << 1];

struct fenwick {
	i64 c[N << 8];
	
	i64 lowbit(i64 x) {
		return x & -x;
	}
	
	void add(i64 x, i64 y) {
		for (i64 i = x; i <= tot; i += lowbit(i))
			c[i] += y;
	}
	
	i64 sum(i64 x) {
		i64 res = 0;
		
		for (i64 i = x; i; i -= lowbit(i))
			(res += c[i]) %= MOD;
		
		return res;
	}
} tr;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		lsh[i] = a[i];
	}
	
	std::sort(lsh + 1, lsh + n + 1);
	tot = std::unique(lsh + 1, lsh + n + 1) - lsh - 1;
	
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(lsh + 1, lsh + tot + 1, a[i]) - lsh;
	
	for (int i = 1; i <= n; i++) {
		i64 w = tr.sum(a[i]) - tr.sum(a[i] - 1);
		tr.add(a[i], tr.sum(a[i] - 1));
		
		if (w)
			tr.add(a[i], -w + 1);
		else
			tr.add(a[i], 1);
	}
	
	std::cout << tr.sum(tot) - tot << "\n";
	return 0;
}
