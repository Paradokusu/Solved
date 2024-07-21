#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    int t0t = 0, cot = 0, mx = a[n], mx2 = a[n - 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) cot++;
        else {
            v[a[i]]++;
        }
    }

    bool flg = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 != 0)
            flg = 1;
    }
    if (cot % 2 == 1) {
        std::cout << "YES\n";
    } else if (cot % 2 == 0 && flg) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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
