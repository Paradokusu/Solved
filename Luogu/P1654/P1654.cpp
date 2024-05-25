#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n;
double p[N], ex[N], ex2[N], ef[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &p[i]);
	
	for (int i = 1; i <= n; i++) {
		ex[i] = p[i] * (ex[i - 1] + 1);
		ex2[i] = p[i] * (ex2[i - 1] + 2 * ex[i - 1] + 1);
		ef[i] = ef[i - 1] + p[i] * (3 * (ex[i - 1] + ex2[i - 1]) + 1);
	}
	
	printf("%.1lf\n", ef[n]);
	return 0;
}
