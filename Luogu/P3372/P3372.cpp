#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 5;

int n, m;
std::array<i64, N> a;
std::array<i64, 4 * N> w, lzy;

bool InRange(int L, int R, int l, int r) {
	return (l <= L) && (R <= r);
}

bool OutOfRange(int L, int R, int l, int r) {
	return (L > r) || (R < l);
}

void maketag(int u, int len, i64 x) {
	lzy[u] += x;
	w[u] += len * x;
}

void pushup(int u) {
	w[u] = w[u << 1] + w[(u << 1) + 1];
}

void pushdown(int u, int L, int R) {
	int M = (L + R) >> 1;
	maketag(u << 1, M - L + 1, lzy[u]);
	maketag((u << 1) + 1, R - M, lzy[u]);
	lzy[u] = 0;
}

void build(int u, int L, int R) {
	if (L == R) {
		w[u] = a[L];
		return;
	}

	int M = (L + R) >> 1;
	build(u << 1, L, M);
	build((u << 1) + 1, M + 1, R);
	pushup(u);
}

i64 query(int u, int L, int R, int l, int r) {
	if (InRange(L, R, l, r)) {
		return w[u];
	} else if (!OutOfRange(L, R, l, r)) {
		int M = (L + R) >> 1;
		pushdown(u, L, R);
		return query(u << 1, L, M, l, r) + query((u << 1) + 1, M + 1, R, l, r);
	} else return 0;
}

void update(int u, int L, int R, int l, int r, i64 x) {
	if (InRange(L, R, l, r)) {
		maketag(u, R - L + 1, x);
	} else if (!OutOfRange(L, R, l, r)) {
		int M = (L + R) >> 1;
		pushdown(u, L, R);
		update(u << 1, L, M, l, r, x);
		update((u << 1) + 1, M + 1, R, l, r, x);
		pushup(u);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	build(1, 1, n);
	while (m--) {
		int op, x, y;
		i64 k;
		std::cin >> op;
		if (op == 1) {
			std::cin >> x >> y >> k;
			update(1, 1, n, x, y, k);
		} else {
			std::cin >> x >> y;
			std::cout << query(1, 1, n, x, y) << "\n";
		}
	}
	return 0;
}
