#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e6 + 7;

int n, m, f[N];
char p[N], t[N];

int main() {
	scanf(" %s", p);
	scanf(" %s", t);
	n = strlen(p);
	m = strlen(t);
	
	for (int i = 0; i < n; i++) {
		int inp;
		scanf("%d", &inp);
		f[inp - 1] = i;
	}
	
	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1, cot = 0;
		for (int i = 0; i < n; i++)
			if (p[i] == t[cot] && mid <= f[i])
				cot++;
		if (cot == m) l = mid;
		else r = mid;
	}
	
	printf("%d\n", l);
	return 0;
}

