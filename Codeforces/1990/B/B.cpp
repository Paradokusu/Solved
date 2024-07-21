#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;
    std::vector<int> a(n, 1);
    int e = -1;
    for (int i = x + 1; i < n; i++) {
        a[i] = e;
        e *= -1;
    }
    e = -1;
    for (int i = y - 1; i >= 0; i--) {
        a[i] = e;
        e *= -1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
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
