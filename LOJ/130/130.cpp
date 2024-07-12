#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n, q;

struct Fenwick {
    i64 tr[N << 1];

    int lowbit(int x) { return x & (-x); }

    void add(int x, i64 v) {    // a[x] += v
        while (x <= n) {
            tr[x] += v;
            x += lowbit(x);
        }
    }

    i64 query(int x) {  // query: 1...x
        i64 res = 0;
        while (x) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }

    i64 sum(int l, int r) {     // sum: l ... r
        return query(r) - query(l - 1);
    }
} bit;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    for (int i = 1, inp; i <= n; i++) {
        std::cin >> inp;
        bit.add(i, inp);
    }

    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1) {
            bit.add(x, y);
        } else {
            std::cout << bit.sum(x, y) << "\n";
        }
    }

    return 0;
}
