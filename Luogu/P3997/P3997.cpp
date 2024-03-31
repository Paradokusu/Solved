#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;

int n, m, k;
int sum[N << 2];

struct node {
	int a, b, c;

	bool operator < (const node &x) const {
		return b < x.b;
	}
} q[N];

void Update(int o, int l, int r, int x, int p) {
	sum[o] += p;

	if (l == r)
		return;

	int mid = (l + r) >> 1;

	if (x <= mid)
		Update(o << 1, l, mid, x, p);
	else
		Update(o << 1 | 1, mid + 1, r, x, p);
}

int Query(int o, int l, int r, int p) {
	if (l == r)
		return l;

	int mid = (l + r) >> 1;

	if (p <= sum[o << 1])
		return Query(o << 1, l, mid, p);
	else
		return Query(o << 1 | 1, mid + 1, r, p - sum[o << 1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> k;
	int cot = 0;

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		if (b > c) {
			q[++cot] = {a, -m, 1};
			q[++cot] = {a, c, -1};
			q[++cot] = {a, b, 1};
			q[++cot] = {a, m, -1};
		} else {
			q[++cot] = {a, b, 1};
			q[++cot] = {a, c, -1};
		}
	}

	std::sort(q + 1, q + cot + 1);

	int now = 0, lst = 0;
	long long ans = 0;

	for (int i = 1; i <= cot; i++) {
		int r = Query(1, 0, 1e5 + 1, now - k + 1);
		ans += 1ll * r * r * (q[i].b - lst);
		now += q[i].c;
		Update(1, 0, 1e5 + 1, q[i].a, q[i].c);
		lst = q[i].b;
	}

	std::cout << ans << "\n";
	return 0;
}
