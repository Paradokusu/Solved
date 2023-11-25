#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 5e4 + 5;

int n, len;	// 块编号和 sqrt(n)
std::array<int, N> id;
std::array<i64, N> a, b, s;

void add(int l, int r, i64 x) {
	int sid = id[l], eid = id[r];
	if (sid == eid) {	// 在同个块中
		for (int i = l; i <= r; i++) a[i] += x, s[sid] += x;
		return;
	}
	for (int i = l; id[i] == sid; i++) a[i] += x, s[sid] += x;
	for (int i = sid + 1; i < eid; i++) b[i] += x, s[i] += len * x;	// 更新完整的块
	for (int i = r; id[i] == eid; i--) a[i] += x, s[eid] += x;
}

i64 query(int l, int r, i64 p) {
	int sid = id[l], eid = id[r];
	i64 ans = 0;
	if (sid == eid) {
		for (int i = l; i <= r; i++) ans = (ans + a[i] + b[sid]) % p;
		return ans;
	}
	for (int i = l; id[i] == sid; i++) ans = (ans + a[i] + b[sid]) % p;
	for (int i = sid + 1; i < eid; i++) ans = (ans + s[i]) % p;
	for (int i = r; id[i] == eid; i--) ans = (ans + a[i] + b[eid]) % p;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	len = std::sqrt(n);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		id[i] = (i - 1) / len + 1;
		s[id[i]] += a[i];
	}
	for (int i = 1; i <= n; i++) {
		int op, l, r;
		i64 c;
		std::cin >> op >> l >> r >> c;
		if (op == 0) add(l, r, c);
		else std::cout << query(l, r, c + 1) << "\n";
	}
	return 0;
}
