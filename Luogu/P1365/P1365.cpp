#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e5 + 7;

int n;
char s[N];
double ans[N], cmb[N];

int main() {
	scanf("%d", &n);
	scanf(" %s", s + 1);
	
	ans[0] = 0, cmb[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'o') {
			ans[i] = ans[i - 1] + cmb[i - 1] * 2 + 1;
			cmb[i] = cmb[i - 1] + 1;
		} else if (s[i] == 'x') {
			cmb[i] = 0;
			ans[i] = ans[i - 1];
		} else if (s[i] == '?') {
			ans[i] = ans[i - 1] + (cmb[i - 1] * 2 + 1) / 2;
			cmb[i] = (cmb[i - 1] + 1) / 2;
		}
	}
	
	printf("%.4lf\n", ans[n]);
	return 0;
}
