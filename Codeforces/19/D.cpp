// Problem: D. Points
// Contest: Codeforces - Codeforces Beta Round 19
// URL: https://codeforces.com/problemset/problem/19/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

struct node {
	std::string opt;
	int x, y;
};

int n;
std::array<int, 4 * N> d;
std::array<node, N> q;
std::set<int> b[N];
std::vector<int> X, Y;

void Build(int u, int L, int R) {
	d[u] = -1;
	if (L < R) {
		const int M = (L + R) >> 1;
		Build(u << 1, L, M);
		Build(u << 1 | 1, M + 1, R);
	}
}

void Update(int u, int L, int R, const int & pos, const int & ch) {
	if (L == R) d[u] = ch;
	else {
		const int M = (L + R) >> 1;
		if (pos <= M) Update(u << 1, L, M, pos, ch);
		else Update(u << 1 | 1, M + 1, R, pos, ch);
		d[u] = std::max(d[u << 1], d[u << 1 | 1]);
	}
}

void Query(int u, int L, int R, const int & l, const int & r, int & x) {
	if (L == R) {
		if (d[u] >= r) x = L;
		return;
	}
	const int M = (L + R) >> 1;
	if (l <= M && d[u << 1] >= r) Query(u << 1, L, M, l, r, x);
	if (~x) return;
	if (d[u << 1 | 1] >= r) Query(u << 1 | 1, M + 1, R, l, r, x);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	X.push_back(-1), Y.push_back(-1);
	std::cin >> n;
	Build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		std::cin >> q[i].opt >> q[i].x >> q[i].y;
		if (q[i].opt[0] == 'f') ++q[i].x, ++q[i].y;
		X.push_back(q[i].x), Y.push_back(q[i].y);
		b[i].insert(-1);
	}
	std::sort(X.begin(), X.end());
	std::sort(Y.begin(), Y.end());
	X.erase(std::unique(X.begin(), X.end()), X.end());
	Y.erase(std::unique(Y.begin(), Y.end()), Y.end());
	for (int i = 1; i <= n; i++) {
		q[i].x = std::lower_bound(X.begin(), X.end(), q[i].x) - X.begin();
		q[i].y = std::lower_bound(Y.begin(), Y.end(), q[i].y) - Y.begin();
		if (q[i].opt[0] == 'a') {
			int mx = *b[q[i].x].rbegin();
			if (mx < q[i].y) Update(1, 1, n, q[i].x, q[i].y);
			b[q[i].x].insert(q[i].y);
		} else if (q[i].opt[0] == 'r') {
			b[q[i].x].erase(b[q[i].x].find(q[i].y));
			Update(1, 1, n, q[i].x, *b[q[i].x].rbegin());
		} else {
			int x = -1;
			Query(1, 1, n, q[i].x, q[i].y, x);
			if (x == -1) std::cout << "-1\n";
			else std::cout << X[x] << " " << Y[*b[x].lower_bound(q[i].y)] << "\n";
		}
	}
	return 0;
}
