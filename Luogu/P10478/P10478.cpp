#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e5 + 7;
constexpr auto inf = std::numeric_limits<int>::max();

int n, m, t0t;
int a[N], inp[N];

struct lnk {
    int l, r;
} d[N];

struct node {
    int w, pos;

    friend bool operator < (const node &x, const node &y) {
        return x.w > y.w;
    }
};

std::priority_queue<node> q;
bool vis[N];

void Ins(int i) {
    d[i].l = i - 1, d[i].r = i + 1;
    q.push({std::abs(a[i]), i});
}

void Del(int i) {
    d[i].l = d[d[i].l].l;
    d[i].r = d[d[i].r].r;
    d[d[i].l].r = i;
    d[d[i].r].l = i;
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &inp[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (inp[i] * a[t0t] < 0) a[++t0t] = inp[i];
        else a[t0t] += inp[i];
    }

    if (a[t0t] < 0)
        t0t--;
    
    int pcnt = 0, psum = 0;
    for (int i = 1; i <= t0t; i++) {
        Ins(i);
        if (a[i] > 0) {
            pcnt++;
            psum += a[i];
        }
    }
    
    d[0].r = 1, d[t0t + 1].l = t0t;
    a[0] = a[t0t + 1] = inf;
 
    if (pcnt <= m) {
        printf("%lld\n", psum);
        exit(0);
    }

    while (pcnt > m) {
        if (q.empty())
            break;
        while (vis[q.top().pos])
            q.pop();
        int u = q.top().pos;
        q.pop();
        if ((d[u].l == 0 || d[u].r == t0t + 1) && a[u] < 0) continue;
        pcnt--, psum -= std::abs(a[u]);
        a[u] += a[d[u].l] + a[d[u].r];
        q.push({std::abs(a[u]), u});
        vis[d[u].l] = vis[d[u].r] = 1;
        Del(u);
    }
    
    printf("%lld\n", psum);
    return 0;
}
