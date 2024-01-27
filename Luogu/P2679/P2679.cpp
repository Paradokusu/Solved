#include <bits/stdc++.h>

constexpr int N = 1e3 + 7;
constexpr int M = 207;
constexpr int MOD = 1000000007;

int n, m, k;
int f[2][N][M], g[2][N][M];
char a[N], b[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s %s", a + 1, b + 1);

    for (int i = 0; i <= n; i++)
        g[0][i][0] = 1;

    int cr = 1;    
    for (int c = 1; c <= k; c++, cr ^= 1) {
        memset(f[cr], 0, sizeof(f[cr]));
        memset(g[cr], 0, sizeof(g[cr]));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j])
                    f[cr][i][j] = (f[cr][i - 1][j - 1] + g[cr ^ 1][i - 1][j - 1]) % MOD;
                g[cr][i][j] = (g[cr][i - 1][j] + f[cr][i][j]) % MOD;
            }
        }
    }

    printf("%d\n", g[cr ^ 1][n][m]);
    return 0;
}

