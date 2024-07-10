#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5007;
constexpr i64 MOD = 1e8;

int n, m;
char a[N], b[N];
i64 f1[2][N], f2[2][N]; // 长度和个数

int main() {
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);

    int ps = 0;
    n = strlen(a + 1) - 1, m = strlen(b + 1) - 1;

    for (int i = 0; i <= m; i++)
        f2[0][i] = 1;
    f2[1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f2[ps ^ 1][j] = 0;
            if (a[i] == b[j]) f1[ps ^ 1][j] = f1[ps][j - 1] + 1;
            else f1[ps ^ 1][j] = std::max(f1[ps][j], f1[ps ^ 1][j - 1]);

            if (a[i] == b[j]) f2[ps ^ 1][j] += f2[ps][j - 1];   // f2[i][j] += f2[i - 1][j - 1]
            if (f1[ps ^ 1][j] == f1[ps ^ 1][j - 1]  /* f1[i][j] == f1[i][j - 1] */) f2[ps ^ 1][j] += f2[ps ^ 1][j - 1];     // f2[i][j] += f2[i][j - 1]
            if (f1[ps ^ 1][j] == f1[ps][j]  /* f1[i][j] == f1[i - 1][j] */) f2[ps ^ 1][j] += f2[ps][j]; // f2[i][j] += f2[i - 1][j]
            if (f1[ps ^ 1][j] == f1[ps][j - 1]  /* f1[i][j] == f1[i - 1][j - 1] */) f2[ps ^ 1][j] -= f2[ps][j - 1]; // f2[i][j] -= f2[i - 1][j - 1]
            f2[ps ^ 1][j] = (f2[ps ^ 1][j] + MOD) % MOD;
        }
        ps ^= 1;
    }

    printf("%lld\n%lld\n", f1[ps][m], f2[ps][m]);
    return 0;
}
