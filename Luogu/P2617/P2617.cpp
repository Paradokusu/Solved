#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

struct node {
	int opt, l, r, k;
} q[N];

int n, m, tot, l, r, k;
int a[N], lsh[N << 1];
char ch;

int sid, eid, num, numz;
int L[N], R[N], bl[N], blv[N << 1];
int sumc[350][N << 1], sums[350][450];

void Mdf(int x, int y) {
	for (int i = bl[x]; i <= num; i++) {
		--sumc[i][a[x]], --sums[i][blv[a[x]]];
		++sumc[i][y], ++sums[i][blv[y]];
	}
	a[x] = y;
}

int ta[N << 1], tc[505];

int Qur(int l, int r, int k) {
	int ans;
	if (bl[l] == bl[r]) {
		int vl, vr, tmp(0);
		for (int i = l; i <= r; i++) ++ta[a[i]], ++tc[blv[a[i]]];
		for (int i = 1; i <= numz; i++) {
			tmp += tc[i];
			if (tmp >= k) {
				tmp -= tc[i], vl = (i - 1) * eid + 1, vr = i * eid;
				break;
			}
		}
		for (int i = vl; i <= vr; i++) {
			tmp += ta[i];
			if (tmp >= k) { ans = lsh[i]; break; }
		}
		for (int i = l; i <= r; i++) ta[a[i]] = 0, tc[blv[a[i]]] = 0;
	} else {
		int vl, vr, tmp(0);
		for (int i = l; i <= R[bl[l]]; i++) ++ta[a[i]], ++tc[blv[a[i]]];
		for (int i = L[bl[r]]; i <= r; i++) ++ta[a[i]], ++tc[blv[a[i]]];
		for (int i = 1; i <= numz; i++) {
			tmp += tc[i] + sums[bl[r] - 1][i] - sums[bl[l]][i];
			if (tmp >= k) {
				tmp -= tc[i] + sums[bl[r] - 1][i] - sums[bl[l]][i], vl = (i - 1) * eid + 1, vr = i * eid;
				break;
			}
		}
		for (int i = vl; i <= vr; i++) {
			tmp += ta[i] + sumc[bl[r] - 1][i] - sumc[bl[l]][i];
			if (tmp >= k) { ans = lsh[i]; break; }
		}
		for (int i = l; i <= R[bl[l]]; i++) ta[a[i]] = 0, tc[blv[a[i]]] = 0;
		for (int i = L[bl[r]]; i <= r; i++) ta[a[i]] = 0, tc[blv[a[i]]] = 0;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); lsh[++tot] = a[i]; }
	for (int i = 1; i <= m; i++) {
		scanf("\n%c %d %d", &ch, &l, &r);
		if (ch == 'Q') { scanf("%d", &k); q[i] = {1, l, r, k}; }
		else { q[i] = {2, l, r, 0}; lsh[++tot] = r; }
	}
	sort(lsh + 1, lsh + tot + 1);
	tot = unique(lsh + 1, lsh + tot + 1) - lsh - 1;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(lsh + 1, lsh + tot + 1, a[i]) - lsh;
	
	sid = ceil(sqrt(n)), eid = ceil(sqrt(tot));
	for (int i = 1; i <= n; i++) bl[i] = (i - 1) / sid + 1;
	for (int i = 1; i <= tot; i++) blv[i] = (i - 1) / eid + 1;
	num = bl[n], numz = blv[tot];
	for (int i = 1; i <= num; i++) {
		L[i] = R[i - 1] + 1, R[i] = min(L[i] + sid - 1, n);
		for (int j = 1; j <= tot; j++) sumc[i][j] = sumc[i - 1][j];
		for (int j = 1; j <= numz; j++) sums[i][j] = sums[i - 1][j];
		for (int j = L[i]; j <= R[i]; j++) ++sumc[i][a[j]], ++sums[i][blv[a[j]]];
	}

	for (int i = 1; i <= m; i++) {
		if (q[i].opt == 1) printf("%d\n", Qur(q[i].l, q[i].r, q[i].k));
		else Mdf(q[i].l, lower_bound(lsh + 1, lsh + tot + 1, q[i].r) - lsh);
	}
	return 0;
}
