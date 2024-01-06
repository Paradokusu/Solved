#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3e5 + 5;

int n, m, cnt;
int a[N], b[N], t[N], lsh[N];
long long f[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x) {
	while (x <= cnt)
		t[x]++, x += lowbit(x);
}

int query(int x) {
	int res = 0;
	
	while (x)
		res += t[x], x -= lowbit(x);
	
	return res;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)  {
		scanf("%d", &a[i]);
		lsh[i] = a[i];
	}
	
	sort(lsh + 1, lsh + n + 1);
	
	for (int i = 2; i <= n + 1; i++)
		if (lsh[i] ^ lsh[i - 1])
			b[++cnt] = lsh[i - 1];

	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
	
	for (int i = n; i >= 1; i--) {
		add(a[i]);
		f[a[i]] += query(a[i] - 1);
	}
	
	for (int i = cnt - 1; i >= 1; i--)
		f[i] += f[i + 1];

	int now = 1;
	printf("%lld\n", f[now]);
	
	for (int i = 1, in; i <= m; i++) {
		scanf("%d", &in);
		now = max(now, a[in] + 1);
		printf("%lld\n", f[now]);
	}
	
	return 0;
}
