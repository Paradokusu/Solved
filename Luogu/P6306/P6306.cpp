#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

constexpr int B = 65536;

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

int n, k;
int tolg[5][B];
int ans;
int s[5];

signed main() {
	n = read<int>(), k = read<int>();
	for (int i = 0; i < n; i++) {
		int inp = read<int>();
		for (int j = 0; j < 4; j++) {
			tolg[j][(B - 1) & inp]++;
			inp >>= 16;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < B; j++)
			if (tolg[i][j] % k == 1)
				ans |= j << (i * 16);
	}
	
	write<int>(ans);
	puts("");
	return 0;
}