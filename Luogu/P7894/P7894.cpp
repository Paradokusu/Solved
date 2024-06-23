#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e6 + 7;
constexpr auto inf = std::numeric_limits<int>::max();

int n, q;
i64 l1 = 1, l2 = 1, r1 = 0, r2 = 0;
i64 tg1, tg2;
i64 x[N], ans[N];
std::pair<i64, i64> p[N], stc1[N << 1], stc2[N << 1];

i64 check1(i64 c) {
    i64 l = l1, r = r1 + 1;
    stc1[r1 + 1].first = inf;
    stc1[0].second = -1;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        if (stc1[mid].first <= c)
            l = mid + 1;
        else r = mid;
    }
    return stc1[l - 1].second;
}

i64 check2(i64 c) {
    i64 l = l2, r = r2 + 1;
    stc2[r2 + 1].first = inf;
    stc2[0].second = -1;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        if (stc2[mid].first <= c)
            l = mid + 1;
        else r = mid;
    }
    return stc2[l - 1].second;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%lld", &p[i].first);
        p[i].second = i;
    }
    x[0] = -inf;
    std::sort(p + 1, p + q + 1);

    i64 tp = 0;
    for (int i = 1; i <= q; i++) {
        i64 y = p[i].first;
        while (tp + 1 <= n && y >= x[tp + 1]) {
            tp++;
            if (tp & 1) {
                i64 ns = x[tp] - x[tp - 1];
                tg1 += ns;
                while (l1 <= r1 && stc1[r1].first >= ns - tg1)
                    r1--;
                stc1[++r1] = {ns - tg1, tp};
                tg2 -= ns;
            } else {
                i64 ns = x[tp] - x[tp - 1];
                tg2 += ns;
                while (l2 <= r2 && stc2[r2].first >= ns - tg2)
                    r2--;
                stc2[++r2] = {ns - tg2, tp};
                tg1 -= ns;
            }
        }

        i64 d = y - x[tp];
        if (d == 0 || !tp) {
            ans[p[i].second] = 0;
            continue;
        }
        if (tp & 1) {
            i64 qr = check1(d - tg1);
            qr = std::max(qr, check2(-d - tg2));
            if (qr == -1) ans[p[i].second] = tp;
            else ans[p[i].second] = tp - qr;
        } else {
            i64 qr = check1(-d - tg1);
            qr = std::max(qr, check2(d - tg2));
            if (qr == -1) ans[p[i].second] = tp;
            else ans[p[i].second] = tp - qr;
        }
    }

    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
