#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

int n, s, t;
double ans;
int a[N], S[N];

int main() {
	scanf("%d %d %d", &n, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		S[i] = S[i - 1] + a[i];
	}
	for (int i = s; i <= t && (double) clock() / CLOCKS_PER_SEC <= 0.95; i++)
		for (int j = i; j <= n; j++)
			ans = max(ans, (S[j] - S[j - i]) / (1.0 * i));
	printf("%.3f\n", ans);
	return 0;
}
