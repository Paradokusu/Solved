#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e4 + 5;

int n, q;
int h[N], lg2[N];
int rmax[N][20], rmin[N][20];

void init() {
	for (int i = 1; i <= n; i++)
		rmax[i][0] = rmin[i][0] = h[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << (j - 1))][j - 1]);
			rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query_max(int A, int B) {	// 求区间最大值
	int x = lg2[B - A + 1];
	return max(rmax[A][x], rmax[B - (1 << x) + 1][x]);
}

int query_min(int A, int B) {	// 求区间最小值
	int x = lg2[B - A + 1];
	return min(rmin[A][x], rmin[B - (1 << x) + 1][x]);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for (int i = 2; i <= n; i++)	// 预处理每个区间长度对应的 k
		lg2[i] = lg2[i >> 1] + 1;

	init();
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", (query_max(l, r) - query_min(l, r)));
	}
	return 0;
}
