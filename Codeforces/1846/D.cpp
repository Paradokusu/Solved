#include <bits/stdc++.h>

double GetArea(double d, double h, double k) {
    return ((double) 2 * d * (h - k) / ((double) 2 * h) * (h - k)) / (double) 2;
}

void solve() {
    int n, d, h;
    std::cin >> n >> d >> h;
    std::vector<int> y(n + 5);
    for (int i = 1; i <= n; i++)
        std::cin >> y[i];

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (double) d * (double) h / 2;
        if (i >= 2 && y[i] - y[i - 1] < h) ans -= GetArea((double) d, (double) h, (double) (y[i] - y[i - 1]));
    }
    std::cout << std::fixed << std::setprecision(8) << ans << "\n";
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
