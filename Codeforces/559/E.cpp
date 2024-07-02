#include <bits/stdc++.h>

constexpr int N = 107;
constexpr auto inf = 0x3f3f3f3f;

int n, ans;
std::pair<int, int> a[N];
int f[N][N][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    std::sort(a + 1, a + n + 1);
    
    a[0].first = -inf;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                int g = a[j].first + a[j].second * k, mx = -inf;
                int id = 0, df = 0;
                for (int l = i + 1; l <= n; l++) {
                    for (int o = 0; o < 2; o++) {
                        int g0 = a[l].first + a[l].second * o;
                        if (g0 > mx) { mx = g0; id = l; df = o; }
                        f[l][id][df] = std::max(f[l][id][df], f[i][j][k] + mx - g0 + std::min(g0 - g, a[l].second));
                    }
                }
                ans = std::max(ans, f[i][j][k]);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
