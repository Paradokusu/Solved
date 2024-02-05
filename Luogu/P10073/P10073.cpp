#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e6 + 7;

int d, n;
int a[N], ans[N];

int main() {
	scanf("%d %d", &d, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int l = 1, r = n;
	while (l <= r) {
		int dl = max(a[l], ans[0] + 1);
		int dr = max(a[r], ans[0] + 1);
		
		if (dl >= dr) {
			ans[0] = dr;
			ans[n - r + l] = r;
			r--;
		} else {
			ans[0] = dl;
			ans[n - r + l] = l;
			l++;
		}
	}

	printf("%d\n", ans[0]);

	for (int i = n; i >= 1; i--)
		printf("%d ", ans[i]);

	printf("\n");	
	return 0;
}
