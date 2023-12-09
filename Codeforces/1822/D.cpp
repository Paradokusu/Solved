#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "1\n";
        return;
    }
    if (n % 2) {
        std::cout << "-1";
    } else {
        for (int i = 0; i < n; i++) {
            if (i % 2) std::cout << i << " ";
            else std::cout << n - i << " ";
        }
    }
    std::cout << "\n";
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
