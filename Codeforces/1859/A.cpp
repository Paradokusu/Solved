#include <bits/stdc++.h>

using i64 = long long;

i64 read() {
    i64 x = 0, f = 1;
    char ch = getchar();
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

void write(i64 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
	constexpr i64 INF = 1e9 + 5;
	i64 n = read();

	i64 minm = INF;
	std::vector<i64> min0;
	for (int i = 1; i <= n; i++) {
		i64 m = read();
		std::vector<i64> v(m);
		for (auto &el : v)
			std::cin >> el;
		i64 minel = *std::min_element(v.begin(), v.end());
		minm = std::min(minm, minel);
		v.erase(std::find(v.begin(), v.end(), minel));
		min0.push_back(*std::min_element(v.begin(), v.end()));
	}
	write(minm + 1ll * std::accumulate(min0.begin(), min0.end(), 0ll) - *std::min_element(min0.begin(), min0.end()));
	puts("");
}

int main() {
	i64 t = read();
	while (t--) {
		solve();
	}
	return 0;
}
