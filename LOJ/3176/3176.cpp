#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> need(3), p(3);

    for (int i = 0; i < 3; i++) {
        std::cin >> need[i];
    }

    std::iota(p.begin(), p.begin() + 3, 0);

    std::sort(p.begin(), p.begin() + 3, [&](int i, int j) {return need[i] < need[j];});

    int a = need[p[0]], b = need[p[1]];
    std::vector<int> siz(n);
    std::vector<std::vector<int>> e(n), ch(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int x = -1;
    std::function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (!siz[v]) {
                ch[u].push_back(v);
                dfs(v);
                siz[u] += siz[v];
            }
        }

        if (x == -1 && siz[u] >= a) {
            x = u;
        }
    };

    dfs(0);

    int cnt = 0;
    std::vector<bool> vis(n);
    std::queue<int> q;

    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u] || u == x) {
            continue;
        }
        ++cnt;
        vis[u] = 1;

        for (auto v : e[u]) {
            q.push(v);
        }
    }

    if (cnt < a) {
        for (int i = 0; i < n; i++) {
            std::cout << 0 << " \n"[i == n - 1];
        }
        return 0;
    }

    std::vector<int> ans(n);
    std::function<void(int, int, int, int &)> paintNotVisited = [&](int u, int s, int c, int &cnt) {
        if (cnt < s && !vis[u] && ans[u] == 0) {
            ++cnt;
            ans[u] = c;
        }

        for (auto v : ch[u]) {
            paintNotVisited(v, s, c, cnt);
        }
    };

    std::function<void(int, int, int, int &)> paint = [&](int u, int s, int c, int &cnt) {
        if (cnt < s && ans[u] == 0) {
            ++cnt;
            ans[u] = c;
        }

        for (auto v : ch[u]) {
            paint(v, s, c, cnt);
        }
    };

    auto workX = [&](int s, int c) {
        int cnt = 0;
        paintNotVisited(x, s, c, cnt);
        
        for (auto v : ch[x]) {
            paint(v, s, c, cnt);
        }
    };

    std::function<void(int, int, int, int &)> paint0 = [&](int u, int s, int c, int &cnt) {
        if (ans[u] || cnt == s) {
            return;
        }
        if (cnt < s) {
            ++cnt;
            ans[u] = c;
        }
        for (auto v : e[u]) {
            paint0(v, s, c, cnt);
        }
    };

    auto work0 = [&](int s, int c) {
        int cnt = 0;
        paint0(0, s, c, cnt);
    };

    if (cnt >= b) {
        workX(a, p[0] + 1);
        work0(b, p[1] + 1);
    } else {
        workX(b, p[1] + 1);
        work0(a, p[0] + 1);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = p[2] + 1;
        }
        std::cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}

