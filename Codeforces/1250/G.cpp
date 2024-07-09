#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, k;
int a[N], b[N];
i64 hmn[N], rbt[N];

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {  // 预处理 reset 操作后得到的值
        hmn[i] = hmn[i - 1] + a[i - 1];
        rbt[i] = rbt[i - 1] + b[i - 1];
        i64 dlt = std::min(hmn[i], rbt[i]);
        hmn[i] -= dlt, rbt[i] -= dlt;
    }

    int pt = n, mn = n;
    i64 hnum = 0, rnum = 0;
    for (int i = n - 1; i >= 0; i--) {  // win 时间点
        hnum += a[i], rnum += b[i];
        while (hmn[i] + hnum >= k) {
            --pt;
            hnum -= a[pt], rnum -= b[pt];
        }
        if (rbt[i] + rnum >= k) mn = i;
    }

    if (mn == n) { printf("-1\n"); return; }
    if (mn == 0) { printf("0\n\n"); return; }

    std::vector<int> ans;
    for (int i = 0; i < mn; i++) {      // 贪心坚持到到最左边端点
        if (hnum + a[i] >= k) {
            i64 dlt = std::min(hnum, rnum);
            hnum -= dlt, rnum -= dlt;
            ans.emplace_back(i);
            if (hnum + a[i] >= k) {
                printf("-1\n");
                return;
            }
        }
        hnum += a[i], rnum += b[i];
    }

    ans.emplace_back(mn);
    printf("%lld\n", ans.size());
    for (auto i : ans)
        printf("%d ", i);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
