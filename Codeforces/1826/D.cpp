#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int T, n, ans;
int a[N], s[N], pre[N], suf[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	ans = suf[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		pre[i] = max(pre[i - 1] - 1, a[i]);
	for (int i = n; i >= 1; i--)
		suf[i] = max(suf[i + 1] - 1, a[i]);
	
	for (int i = 2; i < n; i++)
		ans = max(ans, pre[i - 1] + a[i] + suf[i + 1]);
	printf("%d\n", ans - 2);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
