#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

i64 n, m;
i64 bk[N << 1], L[N << 4], R[N << 4], len[N << 4], v[N << 4];

struct node {
	i64 x, y0, y1, c;
} a[N];

i64 ans;

std::map<i64, i64> sum;

bool cmp(const node &a, const node &b) {
	return a.x < b.x;
}

void Build(int o, int l, int r) {
	L[o] = l;
	R[o] = r;

	if (l == r)
		return;

	i64 mid = (l + r) >> 1;
	Build(o << 1, l, mid);
	Build(o << 1 | 1, mid + 1, r);
}

void Update(i64 o, i64 l, i64 r, i64 dat) {
	if (r < L[o] || l > R[o])
		return;

	if (L[o] >= l && R[o] <= r)
		v[o] += dat;
	else {
		Update(o << 1, l, r, dat);
		Update(o << 1 | 1, l, r, dat);
	}

	if (v[o])
		len[o] = bk[R[o] + 1] - bk[L[o]];	// 减去覆盖的部分
	else
		len[o] = len[o << 1] + len[o << 1 | 1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int x0, y0, x1, y1;
		std::cin >> x0 >> y0 >> x1 >> y1;
		a[i] = {x0, y0, y1, 1};
		a[i + n] = {x1, y0, y1, -1};
		bk[++m] = y1;
		bk[++m] = y0;
	}

	std::sort(bk + 1, bk + m + 1);
	m = std::unique(bk + 1, bk + m + 1) - bk - 1;

	for (int i = 1; i <= m; i++)
		sum[bk[i]] = i;

	n <<= 1;

	Build(1, 1, n);
	std::sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		Update(1, sum[a[i].y0], sum[a[i].y1] - 1, a[i].c);
		ans += 1ll * len[1] * (a[i + 1].x - a[i].x);
	}

	std::cout << ans << "\n";
	return 0;
}
