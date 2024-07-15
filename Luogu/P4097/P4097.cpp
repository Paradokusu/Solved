#include <bits/stdc++.h>

using i64 = long long;
using pdi = std::pair<double, int>;

constexpr int N = 1e5 + 7;
constexpr int P1 = 39989;
constexpr int P2 = 1e9;
constexpr double eps = 1e-9;

int cmp(double x, double y) {
	if (x - y > eps) return 1;
	if (y - x > eps) return -1;
	return 0;
}

struct line {
	double k, b;
} p[N];

int n, lst, t0t;

double gety(int id, int d) { return p[id].b + p[id].k * d; }

void addLine(int ax, int ay, int bx, int by) {
	t0t++;
	if (ax == bx) {	// 无斜率
		p[t0t].k = 0;
		p[t0t].b = std::max(ay, by);
	} else {
		p[t0t].k = 1.0 * (by - ay) / (bx - ax);
		p[t0t].b = ay - ax * p[t0t].k;
	}
}

struct SegTree {
	int tr[N << 2];

	void update1(int o, int l, int r, int u) {	// 修改完全覆盖到的
		int &v = tr[o];
		int mid = (l + r) >> 1;
		int bmid = cmp(gety(u, mid), gety(v, mid));
		if (bmid == 1 || (!bmid && u < v)) std::swap(u, v);
		int fl = cmp(gety(u, l), gety(v, l));
		int fr = cmp(gety(u, r), gety(v, r));
		if (fl == 1 || (!fl && u < v)) update1(o << 1, l, mid, u);
		if (fr == 1 || (!fr && u < v)) update1(o << 1 | 1, mid + 1, r, u);
	}

	void update2(int o, int l, int r, int x, int y, int u) {	// 寻找定位线段完全覆盖的区间
		if (x <= l && r <= y) { update1(o, l, r, u); return; }
		int mid = (l + r) >> 1;
		if (x <= mid) update2(o << 1, l, mid, x, y, u);
		if (y > mid) update2(o << 1 | 1, mid + 1, r, x, y, u);
	}

	pdi pmax(pdi x, pdi y) {
		if (cmp(x.first, y.first) == -1) return y;
		if (cmp(x.first, y.first) == 1) return x;
		return (x.second < y.second ? x : y);
	}

	pdi query(int o, int l, int r, int d) {
		if (r < d || d < l) return {0, 0};
		int mid = (l + r) >> 1;
		double res = gety(tr[o], d);
		if (l == r) return {res, tr[o]};
		return pmax({res, tr[o]}, pmax(query(o << 1, l, mid, d), query(o << 1 | 1, mid + 1, r, d)));
	}
} seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	while (n--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x1, x2, y1, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			x1 = (x1 + lst - 1 + P1) % P1 + 1;
			x2 = (x2 + lst - 1 + P1) % P1 + 1;
			y1 = (y1 + lst - 1 + P2) % P2 + 1;
			y2 = (y2 + lst - 1 + P2) % P2 + 1;
			if (x1 > x2) { std::swap(x1, x2); std::swap(y1, y2); }
			addLine(x1, y1, x2, y2);
			seg.update2(1, 1, P1, x1, x2, t0t);
		} else {
			int x;
			std::cin >> x;
			x = (x + lst - 1 + P1) % P1 + 1;
			lst = seg.query(1, 1, P1, x).second;
			std::cout << lst << "\n";
		}
	}
	return 0;
}
