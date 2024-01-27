#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n, i, j;
    std::cin >> n;

    std::vector<std::vector<int>> r(n + 1, std::vector<int>(n + 1));

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            std::cin >> r[i][j];
        }
    }

    std::vector<int> a(n + 1), maxn(n + 1), minn(n + 1);
    std::fill(maxn.begin(), maxn.end(), -inf);
    std::fill(minn.begin(), minn.end(), inf);

    a[1] = maxn[1] = minn[1] = 0;

    for (i = 2; i <= n; i++) {
        a[i] = a[i - 1] + r[i - 1][i];
        
        for (j = 1; j < i; j++) {
            if (std::max(a[i], maxn[j]) - std::min(a[i], minn[j]) != r[j][i]) {
                break;
            }
        }

        if (j != i) {
            a[i] = a[i - 1] - r[i - 1][i];
        }

        for (j = 1; j <= i; j++) {
            maxn[j] = std::max(maxn[j], a[i]);
            minn[j] = std::min(minn[j], a[i]);
        }
    }

    for (i = 1; i <= n; i++) {
        std::cout << a[i] << " ";
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

