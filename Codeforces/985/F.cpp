#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;
constexpr i64 MOD = 20090313;
constexpr i64 BASE = 12060529;

int n, m;
i64 pw[N], _Hash[26][N];
char s[N];

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

void init() {
	pw[0] = 1;
	for (int i = 1; i < N; i++)
		pw[i] = pw[i - 1] * BASE % MOD;
}

void makeHash() {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 26; j++)
			_Hash[j][i] = (_Hash[j][i - 1] * BASE + 1 + (j == s[i] - 'a')) % MOD;
}

i64 getHash(int o, int l, int r) {
	i64 res = _Hash[o][r];
	l--;
	if (l >= 0) res = (res - _Hash[o][l] * pw[r - l] % MOD + MOD) % MOD;
	return res;
}

int main() {
	init();
	n = read<int>(), m = read<int>();
	scanf(" %s", s + 1);
	makeHash();
	for (int i = 1; i <= m; i++) {
		int l = read<int>(), r = read<int>(), len = read<int>();
		std::multiset<i64> s, t;
		for (int i = 0; i < 26; i++) {
			s.insert(getHash(i, l, l + len - 1));
			t.insert(getHash(i, r, r + len - 1));
		}
		if (s == t)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}