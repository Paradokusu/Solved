// Problem: P6492 [COCI2010-2011#6] STEP
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6492
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

struct node {
	int lv, rv, lenl, lenr, sum, len;
};

int n, q;
std::array<node, N * 4> t;

void Pushup(int u) {
	t[u].lv = t[u << 1].lv;
	t[u].rv = t[u << 1 | 1].rv;
	t[u].lenl = t[u << 1].lenl;
	t[u].lenr = t[u << 1 | 1].lenr;
	t[u].sum = std::max(t[u << 1].sum, t[u << 1 | 1].sum);

	if (t[u << 1].rv != t[u << 1 | 1].lv) {
		t[u].sum = std::max(t[u].sum, t[u << 1].lenr + t[u << 1 | 1].lenl);
		if (t[u << 1].sum == t[u << 1].len) t[u].lenl = t[u << 1].sum + t[u << 1 | 1].lenl;
		if (t[u << 1 | 1].sum == t[u << 1 | 1].len) t[u].lenr = t[u << 1 | 1].sum + t[u << 1].lenr;
	}
}

void Build(int u, int L, int R) {
	t[u].len = (R - L + 1);
	if (L == R) {
		t[u].lv = t[u].rv = 1;
		t[u].lenl = t[u].lenr = 1;
		t[u].sum = 1;
		return;
	}
	
	int M = (L + R) >> 1;
	Build(u << 1, L, M);
	Build(u << 1 | 1, M + 1, R);
	Pushup(u);
}

void Update(int u, int L, int R, int x) {
	if (L == R) {
		t[u].lv ^= 1;
		t[u].rv = t[u].lv;
		return;	
	}
	
	int M = (L + R) / 2;
	if (x <= M) Update(u << 1, L, M, x);
	if (x > M) Update(u << 1 | 1, M + 1, R, x);
	Pushup(u);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> q;
	Build(1, 1, n);
	while (q--) {
		int x;
		std::cin >> x;
		Update(1, 1, n, x);
		std::cout << std::max({t[1].sum, t[1].lenl, t[1].lenr}) << "\n";
	}
	return 0;
}