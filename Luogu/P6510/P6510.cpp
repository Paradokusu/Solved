#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, mxt, mnt;
int a[N], smx[N], smn[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		while (mxt && a[smx[mxt]] < a[i]) mxt--;
		while (mnt && a[smn[mnt]] >= a[i]) mnt--;
		int k = std::upper_bound(smn + 1, smn + mnt + 1, smx[mxt]) - smn;
		if (k != mnt + 1)
			ans = std::max(ans, i - smn[k] + 1);
		smx[++mxt] = i;
		smn[++mnt] = i;
	}
	
	printf("%d\n", ans);
	return 0;
}
