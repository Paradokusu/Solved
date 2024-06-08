#include <bits/stdc++.h>

using namespace std;

constexpr int N = 35007;

struct SegmentTree {
	int tr[N << 2], tag[N << 2];
	
	void pushdown(int o) {
		if (tag[o]) {
			tr[o << 1] += tag[o];
			tag[o << 1] += tag[o];
			tr[o << 1 | 1] += tag[o];
			tag[o << 1 | 1] += tag[o];
			tag[o] = 0;
		}
	}
	
	void modify(int o, int l, int r, int L, int R, int v) {
		if (L > R) return;
		if (L <= l && R >= r) {
			tr[o] += v;
			tag[o] += v;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (L <= mid) modify(o << 1, l, mid, L, R, v);
		if (mid < R) modify(o << 1 | 1, mid + 1, r, L, R, v);
		tr[o] = max(tr[o << 1], tr[o << 1 | 1]);
	}
	
	int query(int o, int l, int r, int L, int R) {
		if (L > R) return 0;
		if (L <= l && R >= r) return tr[o];
		pushdown(o);
		int mid = (l + r) >> 1, res = 0;
		if (L <= mid) res = max(res, query(o << 1, l, mid, L, R));
		if (mid < R) res = max(res, query(o << 1 | 1, mid + 1, r, L, R));
		return res;
	}
} tr[51];

int n, K;
int a[N], pre[N], lst[N];

int main() {
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
		for (int j = 0; j < K; j++) {
			// maintain information
			tr[j].modify(1, 0, n, pre[i], i - 1, 1);
			int tv = tr[j].query(1, 0, n, 0, i - 1);
			tr[j + 1].modify(1, 0, n, i, i, tv); 
		}
	}
	printf("%d\n", tr[K].query(1, 0, n, n, n));
	return 0;
}

