#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 105;

int n, t, m;
i64 S, ans;
std::array<i64, N> a;
std::array<int, N> b;
std::map<std::pair<int, i64>, int> f;

i64 fact(i64 x) {
	i64 res;
	for (res = 1; x; res *= x--)
		if ((S / res) < x) return -1;
	return res;
}

void check1() {
	int cnt = 0;
	i64 sum = 0;
	for (int i = 1; i <= m; i++) {
		if (b[i] == 1) sum += a[i];
		else if (b[i] == 2) {
			i64 s = fact(a[i]);
			if ((s == -1) || (++cnt > t) || ((s + sum) > S)) return;
			sum += s;
		}
	}
	++f[{cnt, sum}];	// 累加方案数
	++f[{-1, sum}];		// 标记 sum 这一和出现过
}

void dfs1(int u) {
	if (u > m) check1();
	else {
		for (int i = 0; i <= 2; i++) {
			b[u] = i;
			dfs1(u + 1);
		}
	}
}

std::map<std::pair<int, i64>, i64> g;

i64 qry(int x, i64 s) {
	if (g.count({x, s})) return g[{x, s}];
	return g[{x, s}] = f[{x, s}] + (x ? qry(x - 1, s) : 0);
}

void check2() {
	int cnt = 0;
	i64 sum = 0;
	for (int i = m + 1; i <= n; i++) {
		if (b[i] == 1) sum += a[i];
		else if (b[i] == 2) {
			i64 s = fact(a[i]);
			if ((s == -1) | (++cnt > t) || ((s + sum) > S)) return;
			sum += s;
		}
	}
	if (f.count({-1, S - sum})) ans += qry(t - cnt, S - sum);
}

void dfs2(int u) {
	if (u > n) check2();
	else {
		for (int i = 0; i <= 2; i++) {
			b[u] = i;
			dfs2(u + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> t >> S;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	m = n >> 1;
	dfs1(1);		// 前半部分搜索
	dfs2(m + 1);	// 后半部分搜索
	std::cout << ans << "\n";
	return 0;
}
