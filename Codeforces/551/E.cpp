#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 7;
constexpr int S = 807;

int n, q, siz;
int pos[N], L[S], R[S];
i64 a[N], add[S];

std::unordered_map<i64, bool> Map[S];

void Build(int i) {
	for (int j = L[i]; j <= R[i]; j++) {
		pos[j] = i;
		Map[i][a[j]] = 1;
	}
	for (int j = R[i]; j >= L[i]; j--)
		Map[i][a[j]] = 1;
}

void Init() {
	siz = sqrt(n);
	for (int i = 1; i <= siz; i++) {
		L[i] = (i - 1) * (n / siz) + 1;
		R[i] = i * (n / siz);
		Build(i);
	}
	if (R[siz] < n) {
		++siz;
		L[siz] = R[siz - 1] + 1;
		R[siz] = n;
		Build(siz);
	}
}

void Add(int l, int r, i64 x) {
	int sid = pos[l], eid = pos[r];
	if (sid == eid) {
		for (int i = L[sid]; i <= R[sid]; i++) Map[sid].erase(a[i]);
		for (int i = l; i <= r; i++) a[i] += x;
		for (int i = L[sid]; i <= R[sid]; i++) Map[sid][a[i]] = 1;
		return;
	}

	for (int i = sid + 1; i <= eid - 1; i++) add[i] += x;
	for (int i = L[sid]; i <= R[sid]; i++) Map[sid].erase(a[i]);
	for (int i = l; i <= R[sid]; i++) a[i] += x;
	for (int i = L[sid]; i <= R[sid]; i++) Map[sid][a[i]] = 1;

	for (int i = L[eid]; i <= R[eid]; i++) Map[eid].erase(a[i]);
	for (int i = L[eid]; i <= r; i++) a[i] += x;
	for (int i = L[eid]; i <= R[eid]; i++) Map[eid][a[i]] = 1;
	return;
}

int Ask(i64 y) {
	int l = -1;
	for (int i = 1; i <= siz; i++) {
		if (Map[i][y - add[i]]) {
			for (int j = L[i]; j <= R[i]; j++) {
				if (a[j] == y - add[i]) {
					l = j;
					break;
				}
			}
			break;
		} else {
			Map[i].erase(y - add[i]);
		}
	}

	if (l == -1) return -1;

	int r = -1;
	for (int i = siz; i >= 1; i--) {
		if (Map[i][y - add[i]]) {
			for (int j = R[i]; j >= L[i]; j--) {
				if (a[j] == y - add[i]) {
					r = j;
					break;
				}
			}
			break;
		} else {
			Map[i].erase(y - add[i]);
		}
	}

	return r - l;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	Init();
	while (q--) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int l, r;
			i64 x;
			std::cin >> l >> r >> x;
			Add(l, r, x);
		} else {
			i64 y;
			std::cin >> y;
			std::cout << Ask(y) << "\n";
		}
	}
	return 0;
}
