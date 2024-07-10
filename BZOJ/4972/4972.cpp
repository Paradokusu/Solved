#include <bits/stdc++.h>

using ui = unsigned int;

constexpr ui N = 3007;

ui n, m, q;
ui A, B, C, x, y, k;
ui ans;

ui a[N][N], s[N][N], h[N][N];

ui rng61(){
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;

    ui t = A;
    A = B;
    B = C;
    C ^= t ^ A;

    return C;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m >> q >> A >> B >> C;

    for (ui i = 1; i <= n; i++)
        for (ui j = 1; j <= m; j++)
            a[i][j] = rng61();

    for (ui i = 1; i <= n; i++)
        for (ui j = m; j >= 1; j--) {
            s[i][j] = s[i][j + 1] + s[i - 1][j + 1] - s[i - 1][j + 2] + a[i][j];
            h[i][j] = h[i][j + 1] + h[i - 1][j] - h[i - 1][j + 1] + a[i][j];
        }

    for (ui i = 1; i <= q; i++) {
        x = rng61() % n + 1;
        y = rng61() % m + 1;
        k = rng61() % std::min(x, y) + 1;

        ui sum = s[x][y - k + 1] - s[x - k][y + 1] - h[x][y + 1] + h[x - k][y + 1];
        ans = ans * 233 + sum;
    }

    std::cout << ans << "\n";
    return 0;
}
