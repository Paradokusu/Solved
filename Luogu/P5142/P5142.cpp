#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7;

int qpow(int b, int p = mod - 2, const int m = mod) {
	b %= m;
	int s = 1 % m;
	for (; p; p >>= 1, b = 1ll * b * b % mod) {
		if (p & 1) {
			s = 1ll * s * b % m;
		}
	}
	return s;
}

long long rnd(int x) {
	return (1ll * x * x) % mod;
}

template <typename T>
struct SegmentTree {
	int n;
	std::vector<T> L, R, s1, s2;
	
	SegmentTree(T n_, std::vector<T> a_) {
		init(n_, a_);
	}
	
	void init(T n_, std::vector<T> a_) {
		n = n_;
		int n4 = n_ * 4 + 1;
		L.resize(n4);
		R.resize(n4);
		s1.resize(n4);
		s2.resize(n4);
		
		std::function<void(int, int, int)> build = [&](int u, int l, int r) {
			L[u] = l, R[u] = r;
			if (l == r) {
				s1[u] = a_[l] % mod;
				s2[u] = rnd(a_[l]) % mod;
				return;
			}
			int mid = (l + r) / 2;
			build(u * 2, l, mid);
			build(u * 2 + 1, mid + 1, r);
			pushup(u);
		};
		build(1, 1, n_);
	}
	
	void pushup(const int u) {
		s1[u] = (s1[u * 2] + s1[u * 2 + 1]) % mod;
		s2[u] = (s2[u * 2] + s2[u * 2 + 1]) % mod;
	}
	
	void update(int u, int k, int v) {
		if (L[u] == R[u]) {
			s1[u] = v % mod;
			s2[u] = rnd(v) % mod;
			return;
		}
		int mid = (L[u] + R[u]) / 2;
		if (k <= mid) update(u * 2, k, v);
		else update(u * 2 + 1, k, v);
		pushup(u);
	}
	
	T query1(int u, int l, int r) {
		if (l == L[u] && r == R[u]) {
			return s1[u] % mod;
		}
		int mid = (L[u] + R[u]) / 2;
		if (r <= mid) {
			return query1(u * 2, l, r) % mod;
		}
		if (l > mid) {
			return query1(u * 2 + 1, l, r) % mod;
		}
		return (query1(u * 2, l, mid) + query1(u * 2 + 1, mid + 1, r)) % mod;
	}
	
	T query2(int u, int l, int r) {
		if (l == L[u] && r == R[u]) {
			return s2[u] % mod;
		}
		int mid = (L[u] + R[u]) / 2;
		if (r <= mid) {
			return query2(u * 2, l, r) % mod;
		}
		if (l > mid) {
			return query2(u * 2 + 1, l, r) % mod;
		}
		return (query2(u * 2, l, mid) + query2(u * 2 + 1, mid + 1, r)) % mod;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	SegmentTree<int> seg(n, a);
	while (m--) {
		int op, x, y;
		std::cin >> op >> x >> y;
		if (op == 1) {
			seg.update(1, x, y % mod);
		} else {
			int s1 = seg.query1(1, x, y) % mod;
			int s2 = seg.query2(1, x, y) % mod;
			int inv = qpow(y - x + 1);
			int ave = 1ll * s1 * inv % mod;
			int ans = 1ll * s2 * inv % mod - 1ll * ave * ave % mod;
			ans = (ans % mod + mod) % mod;
			std::cout << ans << "\n";
		}
	}
	return 0;
}
