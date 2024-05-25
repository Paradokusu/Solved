#include <bits/stdc++.h>

using namespace std;

constexpr int N = 262144 + 7;

int m, ans;
int a[N];

int solve(int l, int r) {
	if (r - l == 1) return 0;
	int mid = (l + r) >> 1;
	int maxL = *max_element(a + l, a + mid);
	int maxR = *max_element(a + mid, a + r);
	
	int res = 0;
	if (maxL > maxR) {
		++res;
		for (int i = 0; i < (mid - l); i++)
			swap(a[l + i], a[mid + i]);
	}
	return solve(l, mid) + solve(mid, r) + res;
}

void work() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	
	ans = solve(0, m);
	if (is_sorted(a, a + m)) printf("%d\n", ans);
	else printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		work();
	}
	return 0;
}
