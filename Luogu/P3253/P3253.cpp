#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;

int n, m, c[N];
long long ans;

struct node {
	int p, a;
	
	friend bool operator < (const node &x, const node &y) {
		return x.a > y.a;
	}
} a[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	for (int i = x; i <= n + m + 1; i += lowbit(i)) {
		c[i] += y;
	}
}

int query(int x) {
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = n, in; i >= 1; i--) {
		scanf("%d", &in);
		a[i] = {i, in};
		add(i, 1);
	}
	
	for (int i = n + 2, in; i <= n + m + 1; i++) {
		scanf("%d", &in);
		a[i] = {i, in};
		add(i, 1);
	}
	
	sort(a + 1, a + n + m + 2);
	int s = n + 1;
	
	for (int i = 1; i <= m + n; i++) {
		node t = a[i];
		ans += abs(query(s) - query(t.p)) - (t.p > s);
		add(t.p, -1);
		s = t.p;
	}
	
	printf("%lld\n", ans);
	return 0;
}
