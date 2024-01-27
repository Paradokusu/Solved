#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 998244353;

template <typename T>
struct Fenwick {
	T n;
	std::vector<T> c;

	Fenwick(T n_) {
		init(n_);
	}

	void init(T n_) {
		n = n_;
		c.resize(n_ * 2 + 1);
	}

	T lowbit(T x) {
		return x & -x;
	}

	void add(T x, T v) {
		for (T i = x; i <= n; i += lowbit(i))
			c[i] += v;
	}

	T sum(T x) {
		T res = 0;
		x = std::min(x, n);
		for (T i = x; i; i -= lowbit(i))
			res += c[i];
		return res;
	}

	T rangeSum(T x, T y) {
		return sum(y) - sum(x);
	}
};

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> p(n + 1), q(k + 1);
	i64 siz = 1ll * std::max(2 * n - 1, k);

	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	for (int i = 1; i <= k; i++) {
		std::cin >> q[i];
		q[i]++;
	}

	Fenwick<i64> fen(1ll * siz);
	i64 ans = 0;

	for (int i = 1; i <= k; i++) {
		fen.add(q[i], 1);
		ans = (ans + i - fen.sum(q[i])) % MOD;
	}

	ans = (ans * n) % MOD;
	std::fill(fen.c.begin(), fen.c.end(), 0);

	for (int i = 1; i <= n; i++) {
		fen.add(p[i], 1);
	}

	for (int i = 1; i <= n; i++) {
		int x = p[i];
		i64 s = 1;

		while (x < 2 * n) {
			int y = x * 2;
			i64 cot = fen.rangeSum(x, y), len = std::max(0ll, k - s);
			ans = (ans + (len + 1) * len / 2 % MOD * cot % MOD) % MOD;
			x *= 2, s++;
		}

		x = p[i], s = 1;

		while (x > 1) {
			int y = (x + 1) / 2;
			i64 cot = fen.rangeSum(y - 1, x - 1), mn = std::min(s, k * 1ll);
			ans = (ans + cot * ((k - 1 + mn) * (k - mn) / 2 % MOD + mn * k % MOD) % MOD) % MOD;
			s++, x = y;
		}

		fen.add(p[i], -1);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
