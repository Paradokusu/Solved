#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;

    i64 ans = 0;
    for (int a = 1; a <= std::min(n, x); a++) {
        for (int b = 1; a * b <= n && a + b <= x; b++) {
            int cR = std::min((n - a * b) / (a + b), x - a - b);
            ans += cR;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
