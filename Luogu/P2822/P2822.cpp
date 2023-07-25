#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 50;

int t, k, n, m;
int ma[N][N], f[N][N];

int main() {
    scanf("%d %d", &t, &k);

    for (int i = 1; i < 2000; i++) {
        ma[i][0] = 1;
        ma[i][i] = 1;
    }

    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j < i; j++)
            ma[i][j] = (ma[i - 1][j] + ma[i - 1][j - 1]) % k;
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            if (!ma[i][j]) f[i][j] += 1;
        }
        f[i][i + 1] = f[i][i];
    }

    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &m);
        if (m > n) m = n;
        printf("%d\n", f[n][m]);
    }

    return 0;
}
