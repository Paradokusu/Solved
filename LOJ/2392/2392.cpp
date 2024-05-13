#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

i64 n, k, T;
i64 x[N << 1];

int extend(int st, int sz, double &co, double &nd, double *a, int type) {
	nd = co = 0;
	
	for (int i = st; i <= sz; i++) {
		if (type == 1) {
			nd = std::max(nd, -co + a[i]);
			co += T - a[i];
		} else {
			nd = std::max(nd, -co + T);
			co += a[i] - T;
		}
		
		if (co >= 0)
			return i;
	}
	
	return sz + 1;
}

bool check(double v) {
	static double a[N], b[N];
	int ca = 0, cb = 0, la = 1, lb = 1;
	int tota = 0, totb = 0, lst = 0;
	
	for (int i = k - 1; i; i--)
		a[++ca] = (x[i + 1] - x[i]) / v / 2;
	
	for (int i = k + 1; i <= n; i++)
		b[++cb] = (x[i] - x[i - 1]) / v / 2;
	
	double da, db, oa, ob, cur = T;
	
	while (la <= ca || lb <= cb) {
		if ((lst == 1 || !lst) && la <= ca)
			tota = extend(la, ca, oa, da, a, 1);
		
		if ((lst == 2 || !lst) && lb <= cb)
			totb = extend(lb, cb, ob, db, b, 1);
		
		bool fla = tota <= ca && cur >= da;
		bool flb = totb <= cb && cur >= db;
		
		if (fla && flb) {
			if (oa >= ob) {
				tota = la = tota + 1;
				cur += oa;
				lst = 1;
			} else {
				totb = lb = totb + 1;
				cur += ob;
				lst = 2;
			}
		} else if (fla) {
			tota = la = tota + 1;
			cur += oa;
			lst = 1;
		} else if (flb) {
			totb = lb = totb + 1;
			cur += ob;
			lst = 2;
		} else if (tota <= ca || totb <= cb) {
			return 0;
		} else
			break;
	}
	
	std::reverse(a + 1, a + ca + 1);
	std::reverse(b + 1, b + cb + 1);

	ca += 1 - la, cb += 1 - lb;
	la = lb = 1;
	lst = 0;
	cur = n * T - (x[n] - x[1]) / v / 2;
	
	while (la <= ca || lb <= cb) {
		if ((lst == 1 || !lst) && la <= ca)
			tota = extend(la, ca, oa, da, a, 2);
		
		if ((lst == 2 || !lst) && lb <= cb)
			totb = extend(lb, cb, ob, db, b, 2);
		
		bool fla = tota <= ca && cur >= da;
		bool flb = totb <= cb && cur >= db;
		
		if (fla && flb) {
			if (oa >= ob) {
				tota = la = tota + 1;
				cur += oa;
				lst = 1;
			} else {
				totb = lb = totb + 1;
				cur += ob;
				lst = 2;
			}
		} else if (fla) {
			tota = la = tota + 1;
			cur += oa;
			lst = 1;
		} else if (flb) {
			totb = lb = totb + 1;
			cur += ob;
			lst = 2;
		} else
			return 0;
	}
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k >> T;
	
	for (int i = 1; i <= n; i++)
		std::cin >> x[i];
	
	if (!x[n]) {
		std::cout << "0\n";
		return 0;
	}
	
	int l = 0, r = 1e9;
	
	while (l < r) {
		int mid = (l + r) >> 1;
		
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	
	std::cout << l << "\n";
	return 0;
}
