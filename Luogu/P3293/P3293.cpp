#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5, M = 1e5 + 5;

struct node_ {
	int ls, rs, sum;
} t[N << 8];

int n, m, cnt, rt[N];

void Psu(const int o) { t[o].sum = t[t[o].ls].sum + t[t[o].rs].sum; }

void Build(int &o, int l, int r) {
	if (!o) o = ++cnt;
	if (l == r) return;
	int mid = l + ((r - l) / 2);
	Build(t[o].ls, l, mid);
	Build(t[o].rs, mid + 1, r);
}

void Ins(int &o, int lsto, int l, int r, int pos) {
	if (!o) o = ++cnt;
	if (l == r) { t[o].sum = t[lsto].sum + 1; return; }
	int mid = l + ((r - l) / 2);
	if (pos <= mid) {
		t[o].rs = t[lsto].rs;
		Ins(t[o].ls, t[lsto].ls, l, mid, pos);
	} else {
		t[o].ls = t[lsto].ls;
		Ins(t[o].rs, t[lsto].rs, mid + 1, r, pos);
	}
	Psu(o);
}

bool Qur(int o, int lsto, int l, int r, int ql, int qr) {
	if (t[lsto].sum - t[o].sum < 1) return 0;
	if (ql <= l && r <= qr) return 1;
	int mid = l + ((r - l) / 2), tot = 0;
	if (ql <= mid) tot += Qur(t[o].ls, t[lsto].ls, l, mid, ql, qr);
	if (qr > mid) tot += Qur(t[o].rs, t[lsto].rs, mid + 1, r, ql, qr);
	return tot;
}

int main() {
	scanf("%d %d", &n, &m);
	Build(rt[0], 0, M);
	for (int i = 1, in; i <= n; i++) { scanf("%d", &in); Ins(rt[i], rt[i - 1], 0, M, in); }
	for (int i = 1; i <= m; i++) {
		int b, x, ql, qr, ans = 0;
		scanf("%d %d %d %d", &b, &x, &ql, &qr);
		for (int j = 17; j >= 0; j--) {
			int L, R, ch;
			if (b & (1 << j)) L = ans, R = ans + ((1 << j) - 1), ch = 0;
			else L = ans + (1 << j), R = ans + ((1 << (j + 1)) - 1), ch = 1;
			if (!Qur(rt[ql - 1], rt[qr], 0, M, max(L - x, 0), min(R - x, M))) ch ^= 1;
			ans += (ch << j);
		}
		printf("%d\n", ans ^ b);
	}
	return 0;
}
