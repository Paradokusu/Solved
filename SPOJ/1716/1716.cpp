#include <bits/stdc++.h>

constexpr int N = 50000 + 7;

int n, q;
int a[N];

struct node {
    int sum, lmax, rmax, ans;
};

struct SegTree {
    node tr[N << 2];

    node pushup(node l, node r) {
        node res;
        res.sum = l.sum + r.sum;
        res.lmax = std::max(l.lmax, l.sum + r.lmax);
        res.rmax = std::max(r.rmax, r.sum + l.rmax);
        res.ans = std::max({l.ans, r.ans, l.rmax + r.lmax});
        return res;
    }

    void build(int o, int l, int r) {
        if (l == r) {
            tr[o].sum = tr[o].lmax = tr[o].rmax = tr[o].ans = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        tr[o] = pushup(tr[o << 1], tr[o << 1 | 1]);
    }

    void update(int o, int l, int r, int x, int v) {
        if (l == r) {
            tr[o].sum = tr[o].lmax = tr[o].rmax = tr[o].ans = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) update(o << 1, l, mid, x, v);
        else update(o << 1 | 1, mid + 1, r, x, v);
        tr[o] = pushup(tr[o << 1], tr[o << 1 | 1]);
    }

    node query(int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) return tr[o];
        int mid = (l + r) >> 1;
        if (y <= mid) return query(o << 1, l, mid, x, y);
        if (x > mid) return query(o << 1 | 1, mid + 1, r, x, y);
        return pushup(query(o << 1, l, mid, x, mid), query(o << 1 | 1, mid + 1, r, mid + 1, y));
    }
} seg;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    seg.build(1, 1, n);
    
    int T;
    std::cin >> T;
    while (T--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 0) seg.update(1, 1, n, x, y);
        else std::cout << seg.query(1, 1, n, x, y).ans << "\n";
    }
    return 0;
}
