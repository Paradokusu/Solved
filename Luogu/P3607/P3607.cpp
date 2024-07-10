#include <bits/stdc++.h>

constexpr int N = 57;
constexpr int S = 50;

int n;
int a[N];
int f[N][N][N][N];  // f[l][r][i][j]: 区间 [l, r]，值域 [i, j]

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int il = 1; il <= a[i]; il++)
            for (int ir = a[i]; ir <= S; ir++)
                f[i][i][il][ir] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            for (int siz = 1; siz <= S; siz++) {
                for (int i = 1, j = siz; j <= S; i++, j++) {
                    f[l][r][i][j] = std::max(f[l][r][i + 1][j], f[l][r][i][j - 1]); // 从小转移到大
                    f[l][r][i][j] = std::max(f[l][r][i][j], f[l + 1][r][i][j] + (a[l] == i));   // 向左扩展
                    f[l][r][i][j] = std::max(f[l][r][i][j], f[l][r - 1][i][j] + (a[r] == j));   // 向右扩展
                    f[l][r][i][j] = std::max(f[l][r][i][j], f[l + 1][r - 1][i][j] + (a[l] == j) + (a[r] == i)); // 反转后最大价值
                }
            }
        }
    }

    printf("%d\n", f[1][n][1][S]);
    return 0;
}
