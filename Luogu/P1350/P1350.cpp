#include <bits/stdc++.h>

constexpr int N = 1e3 + 7;
constexpr int MOD = 1e5 + 3;

int a, b, c, d, k;
int h[N << 1], f[N << 1][N << 1];       // 相当于补全了，所以需要 2 倍空间

// f[i][j] 表示前 i 列放 j 辆车的方案数

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);

    f[0][0] = 1;
    for (int i = 1; i <= c; i++) {
        h[i] = d;
        f[i][0] = 1;
    }
    for (int i = 1; i <= a; i++) {
        h[i + c] = d + b;
        f[i + c][0] = 1;
    }
    for (int j = 1; j <= a + c; j++) {
        for (int i = 1; i <= k; i++)
            f[j][i] = (f[j - 1][i] + f[j - 1][i - 1] * (h[j] - i + 1)) % MOD;
    }

    printf("%d\n", f[a + c][k]);
    return 0;
}
