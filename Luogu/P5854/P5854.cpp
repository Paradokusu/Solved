#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e7 + 7;

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

int n, a[N], d[N];
int top, stc[N];
int ch[N][2];

i64 ls, rs;

int main() {
	n = read<int>();
	for (int i = 1; i <= n; i++)
		a[i] = read<int>();

	stc[++top] = 0;
	for (int i = 1; i <= n; i++) {
		while (top && a[stc[top]] > a[i])
			ch[i][0] = stc[top--];
		if (stc[top])
			ch[stc[top]][1] = i;
		stc[++top] = i;
	}
	
	ls = rs = 0;
	for (int i = 1; i <= n; i++) {
		ls ^= 1ll * i * (ch[i][0] + 1);
		rs ^= 1ll * i * (ch[i][1] + 1);
	}
	
	write<i64>(ls);
	putchar(' ');
	write<i64>(rs);
	puts("");
	
	return 0;
}
