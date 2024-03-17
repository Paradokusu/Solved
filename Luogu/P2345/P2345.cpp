#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e4 + 7;

struct node {
	int v, x;
} a[N];

int n;
i64 ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].v, &a[i].x);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans += max(a[i].v, a[j].v) * abs(a[i].x - a[j].x);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
