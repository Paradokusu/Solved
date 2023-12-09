// Problem: P5283 [十二省联考 2019] 异或粽子
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5283
// Memory Limit: 1 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 5e5 + 5;

int n, k, tot;
std::array<i64, N> a;
std::array<int, 32 * N> sz;
std::array<std::array<int, 2>, 32 * N> trie;

struct node {
	int x, y;	// x 的第 y 大
	i64 w;
	bool operator < (const node &A) const {
		return w < A.w;
	}
};

std::array<node, N> d;
std::priority_queue<node> q;

void Insert(i64 val) {
	int u = 0;
	for (int i = 31; i >= 0; i--) {
		int z = (val >> i) & 1;
		if (!trie[u][z]) trie[u][z] = ++tot;
		u = trie[u][z];
		sz[u]++;
	}
}

i64 Find(i64 val, int t) {
	i64 s = 0;
	int u = 0;
	for (int i = 31, z; i >= 0; i--) {
		z = (val >> i) & 1;
		if (sz[trie[u][z ^ 1]] >= t) u = trie[u][z ^ 1], s |= (1ll << i);
		else t -= sz[trie[u][z ^ 1]], u = trie[u][z];
	}
	return s;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] ^= a[i - 1];
	}
	for (int i = 0; i <= n; i++) Insert(a[i]);
	k *= 2;
	for (int i = 0; i <= n; i++) {
		d[i].w = Find(a[i], 1), d[i].x = i, d[i].y = 1;
		q.push(d[i]);
	}
	i64 ans = 0;
	for (int i = 1; i <= k; i++) {
		node A = q.top();
		q.pop();
		ans += A.w, d[A.x].y++, d[A.x].w = Find(a[A.x], d[A.x].y);
		q.push(d[A.x]);
	}
	ans /= 2;
	std::cout << ans << "\n";
	return 0;
}
