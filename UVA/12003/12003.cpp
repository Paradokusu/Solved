#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 3e5 + 9;
constexpr int S = 600;

int n, m, u;
int siz;
int a[N], bid[N];

vector<int> b[S];

int Qry(int l, int r, int v) {
	int res = 0;

	if (bid[l] == bid[r]) {
		for (int i = l; i <= r; i++)
			if (a[i] < v)
				res++;
		return res;
	}

	for (int i = l; bid[i] == bid[l]; i++) {
		if (a[i] < v)
			res++;
	}
	for (int i = r; bid[i] == bid[r]; i--) {
		if (a[i] < v)
			res++;
	}
	for (int i = bid[l] + 1; i < bid[r]; i++)
		res += lower_bound(b[i].begin(), b[i].end(), v) - b[i].begin();

	return res;
}

void Mdf(int pos, i64 val) {
	vector<int> &v = b[bid[pos]];
	int vpos = lower_bound(v.begin(), v.end(), a[pos]) - v.begin();
	v[vpos] = val;

	while (vpos > 0 && v[vpos] < v[vpos - 1]) {
		swap(v[vpos], v[vpos - 1]);
		--vpos;
	}
	while (vpos < v.size() - 1 && v[vpos] > v[vpos + 1]) {
		swap(v[vpos], v[vpos + 1]);
		++vpos;
	}
	a[pos] = val;
}

int main() {
	scanf("%d %d %d", &n, &m, &u);
	siz = sqrt(n * __lg(n) + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		bid[i] = round(i / siz);
		b[bid[i]].push_back(a[i]);
	}
	bid[0] = -1;
	bid[n + 1] = bid[n] + 1;

	for (int i = 0; i <= bid[n]; i++)
		sort(b[i].begin(), b[i].end());

	while (m--) {
		int l, r, v, p;
		scanf("%d %d %d %d", &l, &r, &v, &p);
		int ans = Qry(l, r, v);
		Mdf(p, 1ll * u * ans / (r - l + 1));
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
	return 0;
}
