#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;
constexpr int K = 2e5;

int n, k;
int num[N], vis[K + 7];

struct node {
    int p, c, l;
} a[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= K; i++)
        if (!vis[i])
            for (int j = i * 2; j <= K; j += i)
                vis[j] = i;
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i].p, &a[i].c, &a[i].l);

    int len = n, ans = 1e9, T = 500;
    while (T--) {
        std::random_shuffle(a + 1, a + len + 1);
        int siz = 0, mx = 0, sum = 0, i = 0;
        for (i = 1; i <= len && sum < k; i++) {
            int j = 1;
            while (vis[num[j] + a[i].c] && j <= siz) j++;
            if (j > siz) { num[++siz] = a[i].c; mx = std::max(mx, a[i].l); sum += a[i].p; }
            if (sum >= k) ans = std::min(ans, mx);
        }
        if (i <= len) {
            int t0t = 0;
            for (int j = 1; j <= len; j++)
                if (a[j].l < mx)
                    a[++t0t] = a[j];
            len = t0t;
        }
    }

    printf("%d\n", (ans != 1e9) ? ans : -1);
    return 0;
}
