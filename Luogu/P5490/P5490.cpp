#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

struct scanLine {
	i64 l, r, h;
	int type;	// 权值 1/-1
} line[N << 1];

bool cmp(const scanLine &a, const scanLine &b) {
	return a.h < b.h;
}

struct node {
	int l, r, sum;	// 被覆盖的次数
	i64 len;	// 区间内被截的长度
};

int n, cot;
i64 X[N << 1];

struct SegTree {
	node tr[N << 2];

	void build(int o, int l, int r) {
		tr[o].l = l, tr[o].r = r;
		tr[o].len = tr[o].sum = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(o << 1, l, mid);
		build(o << 1 | 1, mid + 1, r);
	}

	void pushup(int o) {
		int l = tr[o].l, r = tr[o].r;
		if (tr[o].sum)	// 被覆盖过
			tr[o].len = X[r + 1] - X[l];
		else	// 直接俄合并信息
			tr[o].len = tr[o << 1].len + tr[o << 1 | 1].len;
	}

	void modify(int o, i64 fl, i64 fr, int c) {	//fl, fr: 需要修改的实际范围
		int l = tr[o].l, r = tr[o].r;	// 节点管辖下标范围
		if (X[r + 1] <= fl || fr <= X[l]) return;
		if (fl <= X[l] && X[r + 1] <= fr) {
			tr[o].sum += c;
			pushup(o);
			return;
		}
		modify(o << 1, fl, fr, c);
		modify(o << 1 | 1, fl, fr, c);
		pushup(o);
	}
} seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		X[(i << 1) - 1] = x1, X[(i << 1)] = x2;
		line[(i << 1) - 1] = {x1, x2, y1, 1};
		line[(i << 1)] = {x1, x2, y2, -1};
	}

	n <<= 1;
	std::sort(line + 1, line + n + 1, cmp);
	std::sort(X + 1, X + n + 1);
	int t0t = std::unique(X + 1, X + n + 1) - X - 1;

	seg.build(1, 1, t0t - 1);
	i64 ans = 0;
	for (int i = 1; i < n; i++) {
		seg.modify(1, line[i].l, line[i].r, line[i].type);
		ans += seg.tr[1].len * (line[i + 1].h - line[i].h);
	}

	std::cout << ans << "\n";
	return 0;
}
