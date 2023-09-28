#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 5);
    std::vector<int> b(n + 5);
    
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    if (n == 1) {
        if (a[1] == 1) {
            std::cout << "2\n";
            return;
        } else {
            std::cout << "1\n";
            return;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i - 1] + 1) b[i] = b[i - 1] + 2;
            else b[i] = b[i - 1] + 1;
        }
    }
    std::cout << b[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
