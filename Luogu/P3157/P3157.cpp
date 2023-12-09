#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 5;

int n, m;

struct treeArray {
	int ta[N];
	
	void ub(int& x) { x += x & (-x); }
	void db(int& x) { x -= x & (-x); }
	
	void c(int x, int t) { for (; x <= n + 1; ub(x)) ta[x] += t; }
	int sum(int x) { int r = 0; for (; x > 0; db(x)) r += ta[x]; return r; }
} ta;

struct data_ {
	int val, del, ans;
} a[N];

int rv[N];
i64 res;

bool cmp1(const data_& a, const data_& b) { return a.val < b.val; }
bool cmp2(const data_& a, const data_& b) { return a.del < b.del; }

void solve(int l, int r) {
	if (r - l == 1) { return; }
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid, r);
	int i = l + 1, j = mid + 1;
	while (i <= mid) {
		while (a[i].val > a[j].val && j <= r) { ta.c(a[j].del, 1); j++; }
		a[i].ans += ta.sum(m + 1) - ta.sum(a[i].del), i++;
	}
	i = l + 1, j = mid + 1;
	while (i <= mid) {
		while (a[i].val > a[j].val && j <= r) { ta.c(a[j].del, -1); j++; }
		i++;
	}
	i = mid, j = r;
	while (j > mid) {
		while (a[j].val < a[i].val && i > l) { ta.c(a[i].del, 1); i--; }
		a[j].ans += ta.sum(m + 1) - ta.sum(a[j].del);
		j--;
	}
	i = mid, j = r;
	while (j > mid) {
		while (a[j].val < a[i].val && i > l) { ta.c(a[i].del, -1); i--; }
		j--;
	}
	sort(a + l + 1, a + r + 1, cmp1);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i].val); rv[a[i].val] = i; }
	for (int i = 1, p; i <= m; i++) { scanf("%d", &p); a[rv[p]].del = i; }
	for (int i = 1; i <= n; i++) { if (a[i].del == 0) a[i].del = m + 1; }

	for (int i = 1; i <= n; i++) { res += ta.sum(n + 1) - ta.sum(a[i].val); ta.c(a[i].val, 1); }
	for (int i = 1; i <= n; i++) ta.c(a[i].val, -1);
	solve(0, n);
	sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= m; i++) { printf("%lld\n", res); res -= a[i].ans; }
	return 0;
}
