#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e6 + 7;
constexpr int LOG = 20;

int n, q, x;
int f[N][LOG + 5], d[N];

int LCA(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	int h = d[v] - d[u];
	
	for (int i = LOG; i >= 0; i--) {
		if (h & (1 << i))
			v = f[v][i];
	}
	
	if (u == v) return u;

	for (int i = LOG; i >= 0; i--) {
		if (f[v][i] != f[u][i]) {
			v = f[v][i];
			u = f[u][i];
		}
	}
	
	return f[u][0];
}

int main() {
	n = 4;
	f[2][0] = f[3][0] = f[4][0] = 1;
	int len = 2, a = 2, b = 3;
	d[1] = 0, d[2] = d[3] = d[4] = 1;
	
	scanf("%d", &q);
	while (q--) {
		int u = n + 1, v = n + 2;
		n += 2;
		scanf("%d", &x);
		f[u][0] = f[v][0] = x;
		d[u] = d[v] = d[x] + 1;
		for (int i = 1; (1 << i) <= n; i++) {
			f[u][i] = f[f[u][i - 1]][i - 1];
			f[v][i] = f[f[v][i - 1]][i - 1];
		}
		
		int lca = LCA(a, u);
		if (d[u] + d[a] - d[lca] * 2 > len) {
			b = u;
			len++;
		} else {
			lca = LCA(b, u);
			if (d[u] + d[b] - d[lca] * 2 > len) {
				a = u;
				len++;
			}
		}
		printf("%d\n", len);
	}
	return 0;
}
