#include <bits/stdc++.h>

constexpr int N = 2007;

int n, t0t;
int a[N << 1];
int f[N << 1][N << 1];

std::pair<int, int> d[N << 1];
std::vector<int> ans;
std::vector<std::pair<int, int>> bid[N << 1];

void dfs(int i, int j) {
    int s = 0;
    if (f[i][j] == 0) return;
    for (size_t k = 0; k < bid[i].size(); k++) {
        int r = bid[i][k].second;
        if (r == j) {
            ans.push_back(bid[i][k].first);
            s = 1;
        }
    }
    for (size_t k = 0; k < bid[i].size(); k++) {
        int r = bid[i][k].second;
        if (r < j && (f[i][r] + f[r][j] + s == f[i][j])) {
            dfs(i, r);
            dfs(r, j);
            return;
        }
    }

    if (f[i + 1][j] + s == f[i][j]) {
        dfs(i + 1, j);
        return;
    }
    if (f[i][j - 1] + s == f[i][j]) {
        dfs(i, j - 1);
        return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int c, r;
        scanf("%d %d", &c, &r);
        d[i] = {c - r, c + r};
        a[++t0t] = c - r;
        a[++t0t] = c + r;
    }

    std::sort(a + 1, a + t0t + 1);
    int t = std::unique(a + 1, a + t0t + 1) - a - 1;
    t0t = t;
    for (int i = 1; i <= n; i++) {
        int x = std::lower_bound(a + 1, a + t0t + 1, d[i].first) - a;
        int y = std::lower_bound(a + 1, a + t0t + 1, d[i].second) - a;
        bid[x].push_back({i, y});
    }

    // for (int i = 1; i <= n; i++)
    //     printf("%lld\n", bid[i].size());

    for (int i = t0t; i >= 1; i--) {
        for (int j = i + 1; j <= t0t; j++) {
            int s = 0;
            f[i][j] = std::max(f[i + 1][j], f[i][j - 1]);
            for (size_t k = 0; k < bid[i].size(); k++) {
                int r = bid[i][k].second;
                if (r == j) s = 1;
                if (r < j) f[i][j] = std::max(f[i][j], f[i][r] + f[r][j]);
            }
            f[i][j] += s;
        }
    }

    // for (int i = 1; i <= t0t; i++) {
    //     for (int j = 1; j <= t0t; j++)
    //         printf("%d ", f[i][j]);
    //     printf("\n");
    // }

    dfs(1, t0t);
    
    printf("%lld\n", ans.size());
    for (size_t i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
