#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e6 + 7;

int n, q, s, tot, cnt;
int ls[N << 1], rs[N << 1], dis[N << 1];
int h[N << 1];

struct edge {
    int to, nxt, val;
} e[N << 4];

void addedge(int x, int y, int z) {
    e[++cnt] = {y, h[x], z};
    h[x] = cnt;
}

void build(int &o1, int &o2, int l, int r) {
    if (l == r) {
        o1 = l, o2 = l;
        return;
    }

    if (!o1) o1 = ++tot;
    if (!o2) o2 = ++tot;

    int mid = (l + r) >> 1;
    build(ls[o1], ls[o2], l, mid);
    addedge(ls[o1], o1, 0);
    addedge(o2, ls[o2], 0);

    build(rs[o1], rs[o2], mid + 1, r);
    addedge(rs[o1], o1, 0);
    addedge(o2, rs[o2], 0);
}

void add(int o, int l, int r, int x, int y, int z, int flg) {
    if (x <= l && r <= y) {
        if (flg) addedge(z, o, 0);
        else addedge(o, z, 0);
        return;
    }

    int mid = (l + r) >> 1;
    if (x <= mid)
        add(ls[o], l, mid, x, y, z, flg);
    if (y > mid)
        add(rs[o], mid + 1, r, x, y, z, flg);
}

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    deque<int> q;
    dis[s] = 0;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        
        for (int i = h[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &q, &s);
    
    tot = n;
    int rt1 = 0, rt2 = 0;
    build(rt1, rt2, 1, n);

    while (q--) {
        int x, y, z, w;
        scanf("%d %d %d %d", &x, &y, &z, &w);

        int a = ++tot, b = ++tot;
        addedge(a, b, 1 );
        add(rt1, 1, n, x, y, a, 0);
        add(rt2, 1, n, z, w, b, 1);

        a = ++tot, b = ++tot;
        addedge(a, b, 1);
        add(rt1, 1, n, z, w, a, 0);
        add(rt2, 1, n, x, y, b, 1);
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
        printf("%d\n", dis[i]);
    return 0;
}
