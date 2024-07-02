#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int n, m, ans;

struct lnk {
    int w, l, r;
} a[N];

struct node {
    int val, id;
    friend bool operator < (const node &x, const node &y) {
        return x.val < y.val;
    }
};

bool vis[N];
std::priority_queue<node> q;

void Del(int x) {
    a[x].l = a[a[x].l].l;
    a[x].r = a[a[x].r].r;
    a[a[x].l].r = x;
    a[a[x].r].l = x;
}

int main() {
    scanf("%d %d", &n, &m);
    if (n < 2 * m) { printf("Error!\n"); exit(0); }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].w);
        a[i].l = i - 1, a[i].r = i + 1;
        q.push({a[i].w, i});
    }

    a[1].l = n, a[n].r = 1; // 建环
    for (int i = 1; i <= m; i++) {
        while (vis[q.top().id])
            q.pop();
        auto u = q.top();
        q.pop();
        ans += u.val;
        vis[a[u.id].l] = vis[a[u.id].r] = 1;
        a[u.id].w = a[a[u.id].l].w + a[a[u.id].r].w - a[u.id].w;
        q.push({a[u.id].w, u.id});
        Del(u.id);
    }

    printf("%d\n", ans);
    return 0;
}
