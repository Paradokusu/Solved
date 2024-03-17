#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;

int n, m;
int a[N], b[N], t[N], cnt[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] <= m)
			++cnt[a[i]];
	}
	
	sort(b + 1, b + n + 1);
	int p = unique(b + 1, b + n + 1) - b - 1;
	
	for (int i = 1; i <= p && b[i] <= m; i++) {
		int x = b[i];
		for (int j = x; j <= m; j += x) {
			t[j] += cnt[x];
		}
	}
	
	int ans = t[1], mxt = 1;
	for (int i = 2; i <= m; i++) {
		if (t[i] > ans) {
			ans = t[i];
			mxt = i;
		}
	}
	
	printf("%d %d\n", mxt, ans);
	for (int i = 1; i <= n; i++) {
		if (mxt % a[i] == 0)
			printf("%d ", i);
	}
	
	return 0;
}
