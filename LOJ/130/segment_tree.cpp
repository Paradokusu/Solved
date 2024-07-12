#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n, q;
int a[N];

struct SegTree {
    i64 tr[N << 2];

    void build(int o, int l, int r) {
        if (l == r) { tr[o] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        tr[o] = tr[o << 1] + tr[o << 1 | 1];
    }

    void modify(int o, int l, int r, int x, int v) {    // a[x] += v
        if (l == r) { tr[o] += v; return; }
        int mid = (l + r) >> 1;
        if (x <= mid) modify(o << 1, l, mid , x, v);
        else modify(o << 1 | 1, mid + 1, r, x, v);
        tr[o] = tr[o << 1] + tr[o << 1 | 1];
    }

    i64 query(int o, int l, int r, int x, int y) {      // [x, y]
        if (x <= l && y >= r) { return tr[o]; }
        i64 res = 0;
        int mid = (l + r) >> 1;
        if (x <= mid) res += query(o << 1, l, mid, x, y);
        if (y > mid) res += query(o << 1 | 1, mid + 1, r, x, y);
        return res;
    }
} seg;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    seg.build(1, 1, n);
    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1) {
            seg.modify(1, 1, n, x, y);
        } else {
            std::cout << seg.query(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
