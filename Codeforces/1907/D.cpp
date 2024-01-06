#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int n;
pair<int, int> a[N];

bool check(int k) {
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		l = max(l - k, a[i].first);
		r = min(r + k, a[i].second);
		if (l > r) return 0;
	}
	return 1;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	int l = -1, r = 1e9;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%d\n", r);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
