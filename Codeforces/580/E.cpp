#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int MOD = 20090313;
constexpr int BASE = 12060529;

int n, m, k;
i64 pw[N], val[10][N];
char a[N];

struct node {
    int l, r, tag;
    i64 w;
};

struct seg {
    node tr[N << 8];

    #define ls o << 1
    #define rs o << 1 | 1

    void pushup(int o) {
        tr[o].w = ((tr[ls].w * pw[tr[rs].r - tr[ls].l + 1]) % MOD + tr[rs].w % MOD) % MOD;
    }

    void pushdown(int o) {
        if (tr[o].tag == -1) return;
        int tg = tr[o].tag;
        tr[ls].w = val[tg][tr[ls].r - tr[ls].l + 1];
        tr[rs].w = val[tg][tr[rs].r - tr[rs].l + 1];
        tr[ls].tag = tr[rs].tag = tg;
        tr[o].tg = -1;
    }

    void build(int o, int l, int r) {
        tr[o].l = l, tr[o].r = r, tr[o].tag = -1;
        if (l == r) {
            tr[o].w = a[l] - '0'; 
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(o);
    }

    void update(int o, int l, int r, int x) {
        if (tr[o].l == l && tr[o].r == r) {
            tr[o].tag = x;
            tr[o].w = val[x][tr[o].r - tr[o].l + 1];
            return;
        }
        pushdown(o);
        int mid = (tr[o].l + tr[o].r) >> 1;
        if (mid >= r) update(ls, l, r, x);
        else if (l < mid) update(rs, l, r, x);
        else { update(ls, l, mid, x); update(rs, mid + 1, r, k); }
        pushup(o);
    }

    i64 query(int o, int l, int r) {
        if (tr[o].l == l && tr[o].r == r) return tr[o].w;
        pushdown(o);
        int mid = (tr[o].l + tr[o].r) >> 1;
        if (r <= mid) return query(ls, l, r);
        else if (l > mid) return query(rs, l, r);
        else ((((query(ls, l, mid) % MOD) * pw[r - mid]) % MOD) + (query(rs, mid + 1, r) % MOD)) % MOD;
    }
} ts;

void init() {
    pw[0] = 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    scanf(" %s", a + 1);

    init();
}
