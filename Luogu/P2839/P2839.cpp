#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 5;

int n, w, tot, ans, a[N], rt[N], id[N], q[5];

struct Node {
	int lmax, rmax, sum, mx;
	void Init() { lmax = rmax = -N, sum = 0; }
} Ans;

struct Seg {
	int ls, rs;
	Node v;
} t[N * 20];

Node Mrg(Node a, Node b) {
	Node c;
	c.lmax = max(a.lmax, a.sum + b.lmax);
	c.rmax = max(b.rmax, a.rmax + b.sum);
	c.sum = a.sum + b.sum;
	return c;
}

void Build(int& o, int l, int r) {
	o = ++tot;
	t[o].v.lmax = t[o].v.rmax = t[o].v.sum = r - l + 1;
	if (l == r) return;
	int mid = (l + r) / 2;
	Build(t[o].ls, l, mid), Build(t[o].rs, mid + 1, r);
}

void Mdf(int& o, int l, int r, int p) {
	t[++tot] = t[o], o = tot;
	if (l == r) { t[o].v.lmax = t[o].v.rmax = t[o].v.sum = -1; return; }
	int mid = (l + r) / 2;
	if (p <= mid) Mdf(t[o].ls, l, mid, p);
	else Mdf(t[o].rs, mid + 1, r, p);
	t[o].v = Mrg(t[t[o].ls].v, t[t[o].rs].v);
}

void Qry(int o, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) { Ans = Mrg(Ans, t[o].v); return; }
	int mid = (l + r) / 2;
	if (ql <= mid) Qry(t[o].ls, l, mid, ql, qr);
	if (qr > mid) Qry(t[o].rs, mid + 1, r, ql, qr);
}

int Chk(int mid) {
	int res = 0;
	if (q[1] + 1 <= q[2] - 1) Ans.Init(), Qry(rt[mid], 1, n, q[1] + 1, q[2] - 1), res += Ans.sum;
	Ans.Init(), Qry(rt[mid], 1, n, q[0], q[1]), res += Ans.rmax;
	Ans.Init(), Qry(rt[mid], 1, n, q[2], q[3]), res += Ans.lmax;
	return res >= 0;
}

bool cmp(int x, int y) { return a[x] < a[y]; }

int read();
void write(int x);

int main() {
	n = read(); Build(rt[1], 1, n); t[0].v.Init();
	for (int i = 1; i <= n; i++) { a[i] = read(); id[i] = i; }
	sort(id + 1, id + n + 1, cmp);
	for (int i = 2; i <= n; i++) rt[i] = rt[i - 1], Mdf(rt[i], 1, n, id[i - 1]);
	for (int Q = read(), ans = 0; Q; Q--) {
		for (int i = 0; i < 4; i++) q[i] = (read() + ans) % n + 1;
		sort(q, q + 4);
		int l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (Chk(mid)) ans = a[id[mid]], l = mid + 1;
			else r = mid - 1;
		}
		write(ans);
		puts("");
	}
	return 0;
}

int read() { int x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } return x * f; }

void write(int x) { if (x < 0) putchar('-'), x = -x; if (x > 9) write(x / 10); putchar(x % 10 + '0'); }
