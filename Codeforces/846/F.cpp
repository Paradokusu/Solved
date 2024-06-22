#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n;
i64 ans, all;
int a[N], nxt[N], lst[N];

int main() {
	scanf("%d", &n);
	memset(lst, -1, sizeof(lst));
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i; i--) {
		if (lst[a[i]] == -1)
			lst[a[i]] = n + 1;
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		ans = ans + 1ll * i * (nxt[i] - i);
	ans = ans * 2 - n;
	all = 1ll * n * (n + 1) - n;
	printf("%.6lf\n", 1.0 * ans / all);
	return 0;
}

