#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;

int n, m;
i64 f[N][N], cv[N][N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, inp; i <= n; i++) {
        scanf("%d", &inp);
        for (int j = 1; j <= inp; j++) {
            int a1, a2;
            scanf("%d %d", &a1, &a2);
            for (int b1 = a1; b1; b1--) {
                for (int b2 = a2; b2 <= m; b2++)
                    for (int c = a1; c <= a2; c++)
                        cv[b1][b2][c]++;
            }
        }
    }

    for (int i = 1; i <= m; i++)
        f[i][i] = cv[i][i][i] * cv[i][i][i];
    for (int i = 1; i <= m; i++)
        f[i][i - 1] = 0;
    
    for (int len = 2; len <= m; len++) {
        for (int l = 1; l + len - 1 <= m; l++) {
            int r = l + len - 1;
            for (int i = l; i <= r; i++)
                f[l][r] = std::max(f[l][r], cv[l][r][i] * cv[l][r][i] + f[l][i - 1] + f[i + 1][r]);
        }
    }

    printf("%lld\n", f[1][m]);
    return 0;
}
