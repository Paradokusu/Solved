#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = (1 << 18);

struct node {
    std::pair<i64, int> mx;
    i64 sum;
    int ans;
};

struct SegTree {
    node tr[N << 2];

    int lowbit(int x) { return x & -x; }

    void init() {
        for (int i = 0; i < N * 2; i++)
            tr[i].mx= {-1, -1};
    }

    int gn(int l, int r) {
        if (r - l == 1) { return l * 2 + 1; }
        return (l + r);
    }

    std::pair<std::pair<i64, int>, i64> rangeQuery(int l, int r) {
        std::pair<i64, int> mx{-1, -1};
        i64 sum = 0;
        while (l < r) {
            int p;
            if ((r & (r - 1)) >= l) {
                p = gn(r & (r - 1), r);
                r &= r - 1;
            } else {
                p = gn(l, l + (lowbit(l)));
                l += lowbit(l);
            }
            mx = std::max(mx, tr[p].mx);
            sum += tr[p].sum;
        }
        return {mx, sum};
    }

    int covered(int l, int r, int x, int y) {
        int l1 = std::__lg(l ^ (x - 1));
        int l2 = std::__lg((r - 1) ^ (x - 1));
        int r1 = std::__lg(l ^ y);
        int r2 = std::__lg((r - 1) ^ y);
        if (l1 != l2 || r1 != r2) { return -1; }
        if (l1 < r1) {
            x--;
            x |= (1 << l1) - 1;
            x++;
            y = x + (1 << l1);
        } else {
            y &= ~((1 << r1) - 1);
            x = y - (1 << r1);
        }
        return gn(x, y);
    }

    void query(int l, int r, int x, int y, int &res) {
        if (r - l <= std::max(res, 2)) return;
        int o = covered(l, r, x, y);
        if (o != -1) {
            res = std::max(res, tr[o].ans);
            return;
        }
        auto [mx, sum] = rangeQuery(l, r);
        if (mx.first * 2 < sum) {
            res = r - l;
            return;
        }
        o = mx.second;
        query(l, o, x, y, res);
        query(o + 1, r, x, y, res);
    }

    void pushup(int l, int r) {
        int o = gn(l, r);
        int mid = (l + r) >> 1;
        int pl = gn(l, mid);
        int pr = gn(mid, r);
        tr[o].mx = std::max(tr[pl].mx, tr[pr].mx);
        tr[o].sum = tr[pl].sum + tr[pr].sum;
        tr[o].ans = std::max(tr[pl].ans, tr[pr].ans);

        int x = l, y = r;
        while (y - x > std::max(2, tr[o].ans)) {
            auto [mx, sum] = rangeQuery(x, y);
            if (mx.first * 2 < sum) {
                tr[o].ans = y - x;
                break;
            }
            int z = mx.second;
            if (z < mid) x = z + 1;
            else y = z;
        }
    }

    void modify(int rt, i64 a, int l = 0, int r = N) {
        if (r - l == 1) {
            int o = gn(l, r);
            tr[o] = {.mx{a, rt}, .sum = a, .ans = -1};
            return;
        }
        int mid = (l + r) >> 1;
        if (rt < mid) modify(rt, a, l, mid);
        else modify(rt, a, mid, r);
        pushup(l, r);
    }
} seg;

void solve() {
    int n, q;
    
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        i64 inp;
        std::cin >> inp;
        seg.modify(i, inp);
    }

    for (int i = 0; i < q; i++) {
        int o;
        std::cin >> o;

        if (o == 2) {
            int x;
            i64 y;
            std::cin >> x >> y;
            x--;
            seg.modify(x, y);
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            int ret = -1;
            seg.query(l, r, l, r, ret);
            std::cout << ret << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    seg.init();
    while (T--) {
        solve();
    }
    return 0;
}
