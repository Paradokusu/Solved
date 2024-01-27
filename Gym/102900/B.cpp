#include <bits/stdc++.h>

bool getBomb() {
    char ch;
    std::cin >> ch;
    if (ch == 'X') return 1;
    return 0;
}

void outBomb(bool in) {
    if (in) std::cout << 'X';
    else std::cout << '.';
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> a(n + 1, std::vector<bool>(m + 1));
    int cot = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = getBomb();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (getBomb() != a[i][j]) {
                cot++;
            }
        }
    }

    if (cot <= n * m / 2) { // Âú×ã³éÌëÌõ¼þ
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                outBomb(a[i][j]);
            }
            std::cout << "\n";
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                outBomb(!a[i][j]);
            }
            std::cout << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

