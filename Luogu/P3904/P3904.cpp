#include <bits/stdc++.h>

using i128 = __uint128_t;

constexpr int N = 57;
constexpr auto inf = std::numeric_limits<i128>::max();

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

i128 n, m;
i128 f[N][N];

i128 S(i128 fn, i128 fm) {
    if (f[fn][fm] != inf) return f[fn][fm];
    else f[fn][fm] = S(fn - 1, fm - 1) + fm * S(fn - 1, fm);
    return f[fn][fm];
}

int main() {
    n = read<i128>(), m = read<i128>();
    for (i128 i = 0; i < N; i++) {
        for (i128 j = 0; j < N; j++) {
            f[i][j] = inf;
        }
    }

    for (i128 i = 1; i <= n; i++)
        f[i][1] = 1;
    for (i128 i = 1; i <= m; i++)
        f[0][i] = 0;
    write<i128>(S(n, m));
    return 0;
}
