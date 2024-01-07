#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n, m;
int siz, bid[N], L[N], R[N];
i64 tcr[N], clr[N], sum[N], val[N], fix[N];

void Upd(int l, int r, int x) {
	int sid = bid[l];
	if (tcr[sid]) {
		for (int i = L[sid]; i <= R[sid]; i++) {
			if (i >= l && i <= r) {
				sum[sid] += abs(tcr[sid] - x);
				val[i] += abs(tcr[sid] - x);
				clr[i] = x;
			} else clr[i] = tcr[sid];
		}
	} else {
		for (int i = l; i <= r; i++) {
			sum[sid] += abs(clr[i] - x);
			val[i] += abs(clr[i] - x);
			clr[i] = x;
		}
	}
	tcr[sid] = 0;
	return;
}

void Mdf(int l, int r, int x) {
	int sid = bid[l], eid = bid[r];

	if (sid == eid) {
		Upd(l, r, x);
		return;
	}

	Upd(l, R[sid], x);
	Upd(L[eid], r, x);

	for (int i = sid + 1; i < eid; i++) {
		if (tcr[i]) {
			fix[i] += abs(tcr[i] - x);
			sum[i] += abs(tcr[i] - x) * (R[i] - L[i] + 1);
			tcr[i] = x;
		} else {
			Upd(L[i], R[i], x);
			tcr[i] = x;
		}
	}
}

i64 Qry(int l, int r) {
	int sid = bid[l], eid = bid[r];
	i64 res = 0;

	if (sid == eid) {
		for (int i = l; i <= r; i++)
			res += val[i] + fix[sid];
		return res;
	}

	for (int i = l; i <= R[sid]; i++)
		res += val[i] + fix[sid];
	for (int i = L[eid]; i <= r; i++)
		res += val[i] + fix[eid];
	for (int i = sid + 1; i < eid; i++)
		res += sum[i];

	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	siz = sqrt(n);
	for (int i = 1; i <= n; i++) {
		clr[i] = i;
		bid[i] = (i - 1) / siz + 1;
	}

	for (int i = 1; i <= bid[n]; i++) {
		L[i] = (i - 1) * siz + 1;
		R[i] = i * siz;
	}
	R[bid[n]] = n;

	while (m--) {
		int opt;
		scanf("%d", &opt);
		if (opt == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			Mdf(l, r, x);
		} else if (opt == 2) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", Qry(l, r));
		}
	}
	return 0;
}
