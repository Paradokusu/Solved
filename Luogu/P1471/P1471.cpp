#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 5;

int n, m, Len;
double d;
std::array<int, N> L, R, pos;
std::array<double, N> a, sum, add, sumf;

double Pow(double x) { return x * x; }

void Add(int l, int r, double x) {
	int sid = pos[l], eid = pos[r];
	if (sid == eid) {
		for (int i = l; i <= r; i++) sumf[sid] += 2 * a[i] * x + Pow(x), a[i] += x, sum[sid] += x;
		return;
	}
	for (int i = l; i <= R[sid]; i++) sumf[sid] += 2 * a[i] * x + Pow(x), a[i] += x, sum[sid] += x;
	for (int i = L[eid]; i <= r; i++) sumf[eid] += 2 * a[i] * x + Pow(x), a[i] += x, sum[eid] += x;
	for (int i = sid + 1; i < eid; i++) add[i] += x;
	return;
}

double Query(int l, int r) {
	int sid = pos[l], eid = pos[r], len = r - l + 1;
	double ans = 0;
	if (sid == eid) {
		for (int i = l; i <= r; i++) ans += a[i] + add[sid];
		return ans / 1.0 / len;
	} else {
		for (int i = l; i <= R[sid]; i++) ans += a[i] + add[sid];
		for (int i = L[eid]; i <= r; i++) ans += a[i] + add[eid];
		for (int i = sid + 1; i < eid; i++) ans += sum[i] + add[i] * Len;
		return ans / 1.0 / len;
	}
}

double Ask(int l, int r) {
	int len = r - l + 1, sid = pos[l], eid = pos[r];
	double ave = 0, ans = 0;
	if (sid == eid) {
		for (int i = l; i <= r; i++) ave += a[i] + add[sid], ans += Pow(a[i] + add[sid]);
		return ans / len - Pow(ave / len);
	}
	for (int i = l; i <= R[sid]; i++) ave += a[i] + add[sid], ans += Pow(a[i] + add[sid]);
	for (int i = L[eid]; i <= r; i++) ave += a[i] + add[eid], ans += Pow(a[i] + add[eid]);
	for (int i = sid + 1; i < eid; i++) ave += sum[i] + add[i] * Len, ans += sumf[i] + 2 * sum[i] * add[i] + Len * Pow(add[i]);
	double answer = ans / len - Pow(ave / len);
	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	Len = std::sqrt(n) + 1;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= Len; i++) {
		L[i] = R[i - 1] + 1, R[i] = std::min(R[i - 1] + Len, n);
		for (int j = L[i]; j <= R[i]; j++)
			pos[j] = i, sum[i] += a[j], sumf[i] += Pow(a[j]);
	}
	while (m--) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int l, r;
			double d;
			std::cin >> l >> r >> d;
			Add(l, r, d);
		} else if (opt == 2) {
			int l, r;
			std::cin >> l >> r;
			std::cout << std::fixed << std::setprecision(4) << Query(l, r) << "\n";
		} else if (opt == 3) {
			int l, r;
			std::cin >> l >> r;
			std::cout << std::fixed << std::setprecision(4) << Ask(l, r) << "\n";
		}
	}
	return 0;
}
