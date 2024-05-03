#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, q, s, t;
int a[N];
i64 ans;
i64 tr[N << 8];

i64 calc(i64 x, i64 y) {
    i64 res = 0;

    if (y > x)
        res = -((y - x) * s);
    else
        res = (x - y) * t;
    
    return res;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void update(int u, int l, int r, int x, int y, int w) {
    if (x <= l && r <= y) {
        tr[u] += w;
        return;
    }

    int mid = (l + r) >> 1;

    if (x <= mid)
        update(u << 1, l, mid, x, y, w);
    
    if (y > mid)
        update(u << 1 | 1, mid + 1, r, x, y, w);
}

i64 query(int u, int l, int r, int p) {
    if (l == r)
        return tr[u];
    
    int mid = (l + r) >> 1;

    if (p <= mid)
        return query(u << 1, l, mid, p) + tr[u];
    
    return query(u << 1 | 1, mid + 1, r, p) + tr[u];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> q >> s >> t;

    n++;
    
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    for (int i = 2; i <= n; i++)
        ans += calc(a[i - 1], a[i]);
    
    build(1, 1, n);

    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        
        l++, r++;
        i64 sl = query(1, 1, n, l);
        i64 sr = query(1, 1, n, r);
        update(1, 1, n, l, r, x);

        if (l > 1) {
            i64 w1 = query(1, 1, n, l - 1);
            i64 w2 = query(1, 1, n, l);
            ans += calc(w1, w2) - calc(w1, sl);
        }

        if (r < n) {
            i64 w1 = query(1, 1, n, r + 1);
            i64 w2 = query(1, 1, n, r);
            ans += calc(w2, w1) - calc(sr, w1);
        }

        std::cout << ans << "\n";
    }

    return 0;
}
