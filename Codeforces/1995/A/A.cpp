#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int cot = k;
    if (k == 0) {
        std::cout << "0\n";
        return;
    }
    std::vector<int> cnt(1000);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i + j]++;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         std::cout << cnt[i + j] << " ";
    //     std::cout << "\n";
    // }

    std::vector<int> v;
    for (int i = 0; i < 1000; i++) {
        if (cnt[i] != 0)
            v.push_back(cnt[i]);
    }
    std::sort(v.begin(), v.end(), std::greater<int>());

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (cot > 0) {
            int ov = v[i];
            cot -= v[i];
            v[i] = ov - cot;
            ans++;
            if (cot <= 0) {
                std::cout << ans << "\n";
                return;
            }
        }
    }
    // for (int i = 0; i < v.size(); i++)
    //     std::cout << v[i] << " ";
    // std::cout << "\n";
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
