#include <bits/stdc++.h>

using i64 = long long;

i64 power(i64 a, i64 b, i64 p) {
    i64 ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
    }
    return ans;
}

void solve() {
    i64 a, b, p;
    std::cin >> a >> b >> p;
    std::cout << power(a, b, p) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    solve();
    return 0;
}
