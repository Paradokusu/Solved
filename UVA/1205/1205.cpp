#include <bits/stdc++.h>

constexpr int N = 1e3 + 7;

int n, r;
int fa[N], nxt[N], lst[N], num[N];
double c[N], d[N], tot[N];
bool vis[N];

void solve() {
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        nxt[i] = i;
        lst[i] = i;
        num[i] = 1;
        tot[i] = c[i];
    }

    memcpy(d, c, sizeof(d));

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        fa[b] = a;
    }

    memset(vis, 0, sizeof(vis));

    for (int i = 1; i < n; i++) {
        int p;
        double k = 0;

        for (int j = 1; j <= n; j++) {
            if (j != r && !vis[j] && c[j] > k) {
                k = c[j];
                p = j;
            }
        }

        int f = fa[p];
        
        while (vis[f])
            fa[p] = f = fa[f];
        
        nxt[lst[f]] = p;
        lst[f] = lst[p];
        num[f] += num[p];
        tot[f] += tot[p];
        c[f] = tot[f] / num[f];
        vis[p] = 1;
    }

    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ans += i * d[r];
        r = nxt[r];
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    while (std::cin >> n >> r && n && r) {
        solve();
    }

    return 0;
}
