#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e4 + 5;

int n, len;
int a[N], id[N], addtag[N];
vector<int> ve[N];

void reset(int x) {
	ve[x].clear();
	for (int i = (x - 1) * len + 1; i <= min(x * len, n); i++)
		ve[x].push_back(a[i]);
	sort(ve[x].begin(), ve[x].end());
}

void add(int l, int r, int c) {
	for (int i = l; i <= min(id[l] * len, r); i++) a[i] += c;
	reset(id[l]);
	if (id[l] != id[r]) {
		for (int i = (id[r] - 1) * len + 1; i <= r; i++) a[i] += c;
		reset(id[r]);
	}
	for (int i = id[l] + 1; i <= id[r] - 1; i++) addtag[i] += c;
}

int query(int l, int r, int x) {
	int ans = 0;
	for (int i = l; i <= min(id[l] * len, r); i++)
		if (a[i] + addtag[id[l]] < x) ans++;
	if (id[l] != id[r])
		for (int i = (id[r] - 1) * len + 1; i <= r; i++)
			if (a[i] + addtag[id[r]] < x) ans++;
	for (int i = id[l] + 1; i <= id[r] - 1; i++) {
		int t = x - addtag[i];
		ans += lower_bound(ve[i].begin(), ve[i].end(), t) - ve[i].begin();
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	len = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		id[i] = (i - 1) / len + 1;
		ve[id[i]].push_back(a[i]);
	}
	for (int i = 1; i <= id[n]; i++)
		sort(ve[i].begin(), ve[i].end());
	for (int i = 1; i <= n; i++) {
		int opt, l, r, c;
		scanf("%d %d %d %d", &opt, &l, &r, &c);
		if (opt == 0) add(l, r, c);
		else printf("%d\n", query(l, r, c * c));
	}
	return 0;
}
