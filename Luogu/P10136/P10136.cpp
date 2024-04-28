#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 1e5 + 7;
constexpr i64 inf = LLONG_MAX;

i64 n, len, mnn = inf;
i64 a[N];

std::set<i64> s;

bool check(i64 x) {
    std::set<i64> c;

    for (i64 i = 1; i <= len; i++) {
        c.insert(a[i] % x);

        if (c.size() > 3)
            return 0;
    }

    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n;

    for (i64 i = 1; i <= n; i++) {
        std::cin >> a[i];
        mnn = std::min(mnn, a[i]);
    }

    std::sort(a + 1, a + n + 1);
    len = std::unique(a + 1, a + n + 1) - a - 1;

    if (len <= 3) {
        std::cout << 1ll * (mnn / 4) * (mnn / 4 + 1) / 2;
        return 0;
    }

    for (i64 i = 1; i <= 4; i++) {
        for (i64 j = i + 1; j <= 4; j++) {
            i64 num = std::abs(a[j] - a[i]);

            for (i64 k = 1; k * k <= num; k++) {
                if (num % k != 0)
                    continue;
                
                if (k * 4 > mnn)
                    break;
                
                if (check(k))
                    s.insert(k);
                
                if ((num / k) * 4 <= mnn && check(num / k))
                    s.insert(num / k);
            }
        }
    }

    i64 ans = 0;

    for (auto i : s)
        ans += i;
    
    std::cout << ans << "\n";
    return 0;
}
