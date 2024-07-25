#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 m;
    std::cin >> n >> m;

    std::map<int, int> f;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        f[x]++;
    }

    i64 ans = 0;
    for (auto [x, y] : f) {
        ans = std::max(ans, 1ll * x * std::min(1ll * y, m / x));
        if (f.contains(x + 1)) {
            int z = f[x + 1];
            for (int i = 1; i <= y && 1ll * i * x <= m; i++)
                ans = std::max(ans, 1ll * i * x + 1ll * (x + 1) * std::min(1ll * z, (m - 1ll * i * x) / (x + 1)));
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
