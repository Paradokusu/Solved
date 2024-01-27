#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 107;
constexpr i64 inf = 3e15;

i64 n, k, a[N][N];
i64 ans = -inf, f[N][N][N];

int main() {
    scanf("%lld %lld", &n, &k);
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= i; j++)
            scanf("%lld", &a[i][j]);
    }

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++)
            for (i64 c = 1; c <= n; c++)
                f[i][j][c] = -inf;
    }

    for (i64 j = 1; j <= n; j++) {
        f[n][j][0] = a[n][j];
        f[n][j][1] = a[n][j] * 3;
    }

    for (i64 i = n - 1; i >= 1; i--) {
        for (i64 j = 1; j <= i; j++)
            for (i64 c = 0; i + c - 1 <= n && c <= k; c++) {
                f[i][j][c] = std::max(f[i + 1][j][c], f[i + 1][j + 1][c]) + a[i][j];
                if (c >= 1)
                    f[i][j][c] = std::max(f[i][j][c], std::max(f[i + 1][j][c - 1], f[i + 1][j + 1][c - 1]) + a[i][j] * 3);
            }
    }

    k = std::min(k, n);
    for (i64 i = 0; i <= n; i++)
        ans = std::max(ans, f[1][1][i]);

    printf("%lld\n", ans);
    return 0;
}

