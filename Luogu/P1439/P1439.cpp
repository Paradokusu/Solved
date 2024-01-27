#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, ans;
int a[N], b[N], c[N], f[N], r[N];

int lowbit(int x) {
	return x & -x;
}

int ask(int k) {
	int res = 0;
	for (; k; k -= lowbit(k))
		res = std::max(c[k], res);
	return res;
}

void insert(int k, int x) {
	for (; k < N; k += lowbit(k))
		c[k] = std::max(c[k], x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1, in; i <= n; i++) {
		scanf("%d", &in);
		r[in] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		f[i] = ask(r[a[i]]) + 1;
		insert(r[a[i]], f[i]);
		ans = std::max(ans, f[i]);
	}
	
	printf("%d\n", ans);
	return 0;
}

