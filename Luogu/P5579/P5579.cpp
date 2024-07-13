#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 7;

int n, m;
i64 a[N], psum[N];

struct node {
    i64 hgh, day, sum, mx;
};

struct SegTree {
    node tr[N << 2];

    void build(int o, int l, int r) {
        tr[o].hgh = -1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
    }

    void low(int o, int l, int r, i64 v) {
        tr[o].hgh = tr[o].mx = v;
        tr[o].sum = (i64) (r - l + 1) * v;
        tr[o].day = 0;
    }

    void up(int o, int l, int r, i64 t) {
        tr[o].day += t;
        tr[o].sum += (i64) (psum[r] - psum[l - 1]) * t;
        tr[o].mx += (i64) a[r] * t;
    }

    void pushdown(int o, int l, int r) {
        int mid = (l + r) >> 1;
        if (tr[o].hgh != -1) {
            low(o << 1, l, mid, tr[o].hgh);
            low(o << 1 | 1, mid + 1, r, tr[o].hgh);
            tr[o].hgh = -1;
        }
        if (tr[o].day) {
            up(o << 1, l, mid, tr[o].day);
            up(o << 1 | 1, mid + 1, r, tr[o].day);
            tr[o].day = 0;
        }
    }
    
    i64 modify(int o, int l, int r, int x, int y, i64 v) {
        if (x <= l && r <= y) {
            i64 ori = tr[o].sum;
            low(o, l, r, v);
            return ori - tr[o].sum;
        }
        i64 res = 0;
        int mid = (l + r) >> 1;
        pushdown(o, l, r);
        if (x <= mid) res += modify(o << 1, l, mid, x, y, v);
        if (y > mid) res += modify(o << 1 | 1, mid + 1, r, x, y, v);
        tr[o].sum = tr[o << 1].sum + tr[o << 1 | 1].sum;
        tr[o].mx = tr[o << 1 | 1].mx;
        return res;
    }

    int findLmin(int o, int l, int r, i64 v) {
        if (l == r) return ((tr[o].sum < v) ? n + 1 : l);
        int mid = (l + r) >> 1;
        pushdown(o, l, r);
        if (tr[o << 1].mx >= v) return findLmin(o << 1, l, mid, v);
        return findLmin(o << 1 | 1, mid + 1, r, v);
    }
} seg;

int main() {
    // freopen("1.in", "r", stdin);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + a[i];
    seg.build(1, 1, n);
    
    i64 p = 0;
    while (m--) {
        i64 d, b;
        std::cin >> d >> b;
        seg.up(1, 1, n, d - p);
        p = d;
        std::cout << seg.modify(1, 1, n, seg.findLmin(1, 1, n, b), n, b) << "\n";
    }
    std::cout << "\n";
    return 0;
}
 