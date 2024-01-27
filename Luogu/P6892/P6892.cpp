#include <bits/stdc++.h>

void prt(int f, int t, int x = 0) {
    std::cout << x + f << " to " << x + t << "\n";
}

void solve(int n, int x) {
    if (n == 4) {
        prt(6, -1, x);
        prt(3, 6, x);
        prt(0, 3, x);
        prt(7, 0, x);
        return;
    }

    if (n == 5) {
        prt(8, -1, x);
        prt(3, 8, x);
        prt(6, 3, x);
        prt(0, 6, x);
        prt(9, 0, x);
        return;
    }

    if (n == 6) {
        prt(10, -1, x);
        prt(7, 10, x);
        prt(2, 7, x);
        prt(6, 2, x);
        prt(0, 6, x);
        prt(11, 0, x);
        return;
    }

    if (n == 7) {
        prt(8, -1, x);
        prt(5, 8, x);
        prt(12, 5, x);
        prt(3, 12, x);
        prt(9, 3, x);
        prt(0, 9, x);
        prt(13, 0, x);
        return;
    }

    prt(2 * n - 2, -1, x);
    prt(3, 2 * n - 2, x);
    solve(n - 4, x + 4);
    prt(0, 2 * n - 5, x);
    prt(2 * n - 1, 0, x);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 3) {
        prt(2, -1);
        prt(5, 2);
        prt(3, -3);
        return 0;
    }

    solve(n, 0);

    return 0;
}

