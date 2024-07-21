#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        ans += a[i];
    }

    std::function<void()> work = [&]() {
        std::vector<bool> c(n + 1);
        int mxu = 0;
        for (int i = 1; i <= n; i++) {
            if (c[a[i]])
                mxu = std::max(mxu, a[i]);
            c[a[i]] = 1;
            a[i] = mxu;
        }
    };

    work();
    for (int i = 1; i <= n; i++)
        ans += a[i];
    work();

    for (int i = 1; i <= n; i++) {
        ans += 1ll * (n - i + 1) * a[i];
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
