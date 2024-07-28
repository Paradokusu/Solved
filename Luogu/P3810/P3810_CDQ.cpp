#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, k;
int ans[N];

struct node {
    int a, b, c, x, ans;
} a[N], t[N];

bool cmp(const node &p, const node &q) {
    return p.a != q.a ? p.a < q.a : p.b != q.b ? p.b < q.b : p.c < q.c;
}

struct Fenwick {
    int tr[N << 2];
    
    int lowbit(int x) { return x & -x; }
    
    void add(int i, int x) {
        for (; i <= k; i += lowbit(i))
            tr[i] += x;
    }

    int sum(int i) {
        int res = 0;
        for (; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
} bit;

void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    int p = l, q = mid + 1, len = 0;
    cdq(l, mid);
    cdq(mid + 1, r);
    while (p <= mid && q <= r) {    // merge subrange
        if (a[p].b <= a[q].b) {
            bit.add(a[p].c, a[p].x);
            t[++len] = a[p++];
        } else {
            a[q].ans += bit.sum(a[q].c);
            t[++len] = a[q++];
        }
    }
    while (p <= mid) {  // merge left
        bit.add(a[p].c, a[p].x);
        t[++len] = a[p++];
    }
    while (q <= r) {    // merge right
        a[q].ans += bit.sum(a[q].c);
        t[++len] = a[q++];
    }

    for (int i = l; i <= mid; i++)  // clear
        bit.add(a[i].c, -a[i].x);
    for (int i = 1; i <= len; i++)  // copy tmp to origin
        a[l + i - 1] = t[i];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].x = 1;
        a[i].ans = 0;
    }
    std::sort(a + 1, a + n + 1, cmp);
    int t0t = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i].a == a[t0t].a && a[i].b == a[t0t].b && a[i].c == a[t0t].c)
            ++a[t0t].x;
        else
            a[++t0t] = a[i];
    }
    cdq(1, t0t);
    for (int i = 1; i <= t0t; i++)
        ans[a[i].ans + a[i].x - 1] += a[i].x;   // x: sum of a_s = a_p, b_s = b_p, c_s = c_p
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << "\n";
    return 0;
}
