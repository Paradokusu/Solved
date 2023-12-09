#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e4 + 5;

int n, len;
int a[N], id[N], sum[N];

void add(int l, int r, int x) {
	for (int i = l; i <= min(id[l] * len, r); i++) a[i] += x;
	if (id[l] != id[r])
		for (int i = (id[r] - 1) * len + 1; i <= r; i++) a[i] += x;
	for(int i = id[l] + 1; i <= id[r] - 1; i++)
		sum[i] += x;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	len = sqrt(n);
	for (int i = 1; i <= n; i++) id[i] = (i - 1) / len + 1;
	for (int i = 1; i <= n; i++) {
		int op, l, r, c;
		scanf("%d %d %d %d", &op, &l, &r, &c);
		if (op == 0) add(l, r, c);
		else if (op == 1) printf("%d\n", a[r] + sum[id[r]]);
	}
	return 0;
}
