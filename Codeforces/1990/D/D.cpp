#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    bool f1 = 0, f2 = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((!f1) && (!f2)) {
            if (a[i] == 0) continue;
            ans++;
            if (a[i] <= 2) f1 = 1;
        } else if (f1) {
            f1 = 0;
            if (a[i] <= 2) continue;
            ans++;
            if (a[i] <= 4) f2 = 1;
        } else {
            f2 = 0;
            if (a[i] == 0) continue;
            ans++;
            if (a[i] <= 4) f1 = 1;
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
