#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;

int m, n, k, t;
int a[N], l[N], r[N], d[N];

bool check(int x) {
	int mn = (int) 1e9;
	for (int i = 1; i <= x; i++) mn = min(mn, a[i]);
	vector<pair<int, int>> segm;
	for (int i = 1; i <= k; i++)
		if (d[i] > mn) segm.push_back({l[i], r[i]});
	int reqt = 0;
	sort(segm.begin(), segm.end());
	int lstr = 0;
	for (auto i : segm) {
		if (i.first <= lstr) reqt += max(0, i.second - lstr), lstr = max(i.second, lstr);
		else reqt += i.second - i.first + 1, lstr = i.second;
	}
	reqt = 2 * reqt + n + 1;
	return reqt <= t;
}

int main() {
	scanf("%d %d %d %d", &m, &n, &k, &t);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++) scanf("%d %d %d", &l[i], &r[i], &d[i]);
	sort(a + 1, a + m + 1);
	reverse(a + 1, a + m + 1);
	int l = 0, r = m + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}
