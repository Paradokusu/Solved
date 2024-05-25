#include <bits/stdc++.h>

using namespace std;
constexpr int N = 27;

int T, n, r;
double res;
double P[N], sum[N];

int main() {
	while (scanf("%d %d", &n, &r)) {
		T++, res = 0;
		
		if (n == 0 && r == 0) break;
		
		for (int i = 0; i < n; i++) {
			sum[i] = 0;
			scanf("%lf", &P[i]);
		}
		
		for (int i = 0; i < (1 << n); i++) {
			if (__builtin_popcount(i) != r)
				continue;
			double cot = 1;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) cot *= P[j];
				else cot *= (1 - P[j]);
			}
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) sum[j] += cot;
			res += cot;
		}
		
		printf("Case %d:\n", T);
		for (int i = 0; i < n; i++)
			printf("%.6lf\n", sum[i] / res);
	}
	return 0;
}
