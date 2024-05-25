#include <bits/stdc++.h>

using namespace std;

constexpr int N = 30;

int n, c[N];

int main() {
	scanf("%d", &n);
	
	c[0] = 1, c[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
			c[i] += c[j] * c[i - j - 1];

	printf("%d\n", c[n]);
	return 0;
}
