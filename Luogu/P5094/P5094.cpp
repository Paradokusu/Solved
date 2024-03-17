#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e4 + 7;
constexpr int R = 5e4;

struct node {
	int v, x;
} a[N];

int n;
i64 ans, cot;
i64 tr1[N << 1], tr2[N << 1];

bool cmp(const node &a, const node &b) {
	return a.v < b.v;
}

int lowbit(int x) {
	return x & (-x);
}

void add1(int i, int x) {
	for (; i <= R; i += lowbit(i))
		tr1[i] += x;
}

i64 query1(int x) {
	i64 res = 0;
	for (; x; x -= lowbit(x))
		res += tr1[x];
	return res;
}

void add2(int i, int x) {
	for (; i <= R; i += lowbit(i))
		tr2[i] += x;
}

i64 query2(int x) {
	i64 res = 0;
	for (; x; x -= lowbit(x))
		res += tr2[x];
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].v, &a[i].x);
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		i64 num = query1(a[i].x);
		i64 sum = query2(a[i].x);
		ans += (num * a[i].x - sum) * a[i].v;
		ans += ((cot - sum) - (i - num - 1) * a[i].x) * a[i].v;
		add1(a[i].x, 1);
		add2(a[i].x, a[i].x);
		cot += a[i].x;
	}
	
	printf("%lld\n", ans);
	return 0;
}
