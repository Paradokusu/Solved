#include <bits/stdc++.h>

using namespace std;

int n;
double ans = 1.0;

int main() {
	scanf("%d", &n);
	n >>= 1;
	
	for (int i = 1; i <= n - 1; i++)
		ans = ans * (i + n - 1) / (i * 4);
	
	printf("%.4lf\n", 1 - ans);
}
