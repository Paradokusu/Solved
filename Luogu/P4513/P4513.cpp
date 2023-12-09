#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 5e5 + 5;

struct node {
	int sum, lv, rv;
	int tot;
};

int n, m;
std::array<int, N> a;
std::array<node, 4 * N> w;

bool InRange(int L, int R, int l, int r) {
	return (l <= L) && (r >= R);
}

void Pushup(const int u, int L, int R) {
	w[u].sum = std::max({w[u * 2].sum, w[u * 2 + 1].sum, w[u * 2].rv + w[u * 2 + 1].lv});
	w[u].tot = w[u * 2].tot + w[u * 2 + 1].tot;
	w[u].lv = std::max(w[u * 2].lv, w[u * 2].tot + w[u * 2 + 1].lv);
	w[u].rv = std::max(w[u * 2 + 1].rv, w[u * 2 + 1].tot + w[u * 2].rv);
}

void Build(int u, int L, int R) {
	if (L == R) {
		w[u].sum = w[u].lv = w[u].rv = w[u].tot = a[L];
		return;
	}
	
	int M = (L + R) / 2;
	Build(u * 2, L, M);
	Build(u * 2 + 1, M + 1, R);
	Pushup(u, L, R);
}

void Update(int u, int L, int R, int x, int k) {
	if (L == R && R == x) {
		w[u].sum = w[u].lv = w[u].rv = w[u].tot = k;
		return;
	}
	
	int M = (L + R) / 2;
	if (x <= M) Update(u * 2, L, M, x, k);
	if (x > M) Update(u * 2 + 1, M + 1, R, x, k);
	Pushup(u, L, R);
}

node Query(int u, int L, int R, int l, int r) {
	if (InRange(L, R, l, r)) return w[u];
	
	int M = (L + R) / 2;
	if (l > M) return Query(u * 2 + 1, M + 1, R, l, r);
	if (r <= M) return Query(u * 2, L, M, l, r);
	node sl = Query(u * 2, L, M, l, r), sr = Query(u * 2 + 1, M + 1, R, l, r);
	node ans;
	ans.tot = sl.tot + sr.tot;
	ans.sum = std::max({sl.sum, sr.sum, sl.rv + sr.lv});
	ans.lv = std::max(sl.lv, sl.tot + sr.lv);
	ans.rv = std::max(sr.rv, sr.tot + sl.rv);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	Build(1, 1, n);
	while (m--) {
		int k;
		std::cin >> k;
		if (k == 1) {
			int a, b;
			std::cin >> a >> b;
			if (a > b) std::swap(a, b);
			std::cout << Query(1, 1, n, a, b).sum << "\n";
		} else if (k == 2) {
			int p, s;
			std::cin >> p >> s;
			Update(1, 1, n, p, s);
		}
	}
	return 0;
}
