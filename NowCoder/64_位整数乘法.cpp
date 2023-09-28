#include <bits/stdc++.h>

using i64 = long long;

i64 mul(i64 a, i64 b, i64 p) {
    i64 ans = 0;
    for (; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

void solve() {
    i64 a, b, p;
    std::cin >> a >> b >> p;
    std::cout << mul(a, b, p) << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
