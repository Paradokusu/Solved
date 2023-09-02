#include <bits/stdc++.h>

typedef unsigned long long i64;

inline i64 read() {
    register i64 x = 0, f = 1;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(i64 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}


void solve() {
	i64 n, d, p;
	n = read(), d = read(), p = read();
	std::vector<i64> f(n + 5);

	i64 tot = 0;
	for (i64 i = 1; i <= n; i++) {
		f[i] = read();
		tot += f[i];
	}

	i64 ans = 1e18;
	std::sort(f.begin(), f.end(), std::greater<i64>());
	std::vector<i64> cnt(n + 5);
	cnt[0] = f[0];
	for (i64 i = 1; i < n; i++)
		cnt[i] = f[i] + cnt[i - 1];
	for (i64 i = d; i; i += d) {
		i64 sum = tot;
		if (i >= n) {
			sum = ((i / d) * p);
			ans = std::min(ans, sum);
			break;
		} else {
			sum -= cnt[i - 1];
			sum += ((i / d) * p);
			ans = std::min(ans, sum);
		}
	}

	write(std::min(ans, tot));
	puts("");
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
