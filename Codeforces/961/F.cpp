#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;
constexpr int MOD = 20090313;
constexpr int BASE = 12060529;

int n, m, ans;
int pw[N], _Hash[N], f[N];
char s[N];

void init() {
	m = (n - 1) >> 1;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = (1ll * pw[i - 1] * BASE) % MOD;
}

void makeHash(int x) {
	_Hash[x] = (1ll * _Hash[x - 1] * BASE + (s[x] - 'a')) % MOD;
}

int getHash(int l, int r) {
	int p = r - l + 1;
	return (_Hash[r] + MOD - 1ll * pw[p] * _Hash[l - 1] % MOD) % MOD;
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s + 1);
	
	init();
	for (int i = 1; i <= n; i++)
		makeHash(i);
	
	f[m + 1] = -1;
	for (int i = m; i != -1; i--) {
		f[i] = f[i + 1] + 2;
		while ((f[i] != -1) && (i << 1) + f[i] >= n)
			f[i] -= 2;
		while ((f[i] != -1) && (getHash(i + 1, i + f[i]) != getHash(n - i - f[i] + 1, n - i)))
			f[i] -= 2;
	}
	
	for (int i = 0; i <= m; i++)
		printf("%d ", f[i]);
	printf("\n");
	return 0;
}
