#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int n, q, c;
int a[N], lst[N], g[N];
int tag[N], pre[N];

struct node {
    int u, v;
} b[N];

void solve() {
    std::cin >> n >> q >> c;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        lst[i] = a[i] ? lst[i - 1] : i;
        g[i] = i + 1;
    }

    for (int i = 1; i <= q; i++) {
        int u, v;
        std::cin >> u >> v;
        b[i] = {u, v - 1};
    }

    for (int i = 1; i <= q; i++) {
        g[b[i].u] = b[i].v + 1;
        tag[b[i].v + 1] = 1;
    }

    pre[0] = 1;

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + tag[i];

        for (int j = i; j < g[i]; j++)
            pre[i] = std::max(pre[i], a[j]);
        
        for (int j = i; j < g[i]; j++)
            pre[j] = pre[i];
        
        i = g[i] - 1;
    }

    bool flg = 1;

    for (int i = 1; i <= n; i++) {
        if (!a[i])
            a[i] = (pre[i - 1] == pre[i]) ? 1 : pre[i];
        else if (pre[i] != pre[i - 1] && pre[i] > a[i])
            if (lst[i])
                a[lst[i]] = pre[i];
        
        if (a[i] > c)
            flg = 0;
        
        pre[i] = std::max({pre[i], pre[i - 1], a[i]});
        tag[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        pre[i] = std::max(pre[i - 1], a[i]);
    
    for (int i = 1; i <= q; i++)
        if (pre[b[i].u] < pre[b[i].v] || pre[b[i].u] == pre[b[i].v + 1])
            flg = 0;
    
    if (!flg)
        std::cout << "-1\n";
    else {
        for (int i = 1; i <= n; i++)
            std::cout << a[i] << " ";
        
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
