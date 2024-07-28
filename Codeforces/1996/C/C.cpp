#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> pre1(n + 1, std::vector<int>(30));
    std::vector<std::vector<int>> pre2(n + 1, std::vector<int>(30));

    for (int i = 1; i <= n; i++) {
        char x;
        std::cin >> x;
        pre1[i][x - 'a']++;
        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++) {
        char x;
        std::cin >> x;
        pre2[i][x - 'a']++;
        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int cot = 0;
        for (int c = 0; c < 26; c++) {
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];
            cot += std::abs(v1 - v2);
        }
        std::cout << cot / 2 << "\n";
    }
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
