#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;
constexpr int inf = 2147483647;

int n, m;
int a[N], mn[N << 2];

void build(int o, int l, int r) {
	if (l == r) {
		mn[o] = a[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	mn[o] = std::min(mn[o << 1], mn[o << 1 | 1]);
}

int query(int o, int l, int r, int x, int y) {
	if (l > y || x > r)
		return inf;
	
	if (l >= x && r <= y)
		return mn[o];
	
	int mid = (l + r) >> 1;
	int rt = inf;
	
	if (y < mid)
		rt = std::min(rt, query(o << 1, l, mid, x, y));
	else if (x > mid)
		rt = std::min(rt, query(o << 1 | 1, mid + 1, r, x, y));
	else
		rt = std::min(query(o << 1, l, mid, x, y), query(o << 1 | 1, mid + 1, r, x, y));
	
	return rt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	memset(mn, 0x3f, sizeof(mn));
	
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	build(1, 1, n);
	
	for (int i = 1; i <= n - m + 1; i++)
		std::cout << query(1, 1, n, i, i + m - 1) << "\n";
	
	return 0;
}
