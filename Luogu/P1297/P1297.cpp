#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e7 + 7;

int n;
int A, B, C;
i64 a[N];
double ans;

int main() {
	scanf("%d %d %d %d %lld", &n, &A, &B, &C, &a[1]);
	for (int i = 2; i <= n; i++)
		a[i] = ((i64) a[i - 1] * A + B) % 100000001;
	for (int i = 1; i <= n; i++)
		a[i] = a[i] % C + 1;
	a[n + 1] = a[1];

	for (int i = 1; i <= n; i++)
		ans += 1 / (double) max(a[i], a[i + 1]);
	printf("%.3lf\n", ans);
	return 0;
}
