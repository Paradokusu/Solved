#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int M = N << 1;

int n, m, cot;
int st[N], ind[N], otd[N];
bool vis[M];

std::stack<int> ans;
std::vector<std::pair<int, int>> G[N];  // (v (to), c (id))

void dfs(int u) {
    for (int i = st[u]; i < G[u].size(); i = std::max(i + 1, st[u])) {
        int v = G[u][i].first, id = G[u][i].second;
        if (!vis[id]) {
            vis[id] = 1;
            st[u] = i + 1;
            dfs(v);
        }
    }
    ans.push(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s = 0, t = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        otd[u]++, ind[v]++;
        G[u].push_back({v, i});
    }

    for (int i = 1; i <= n; i++) {
        if (ind[i] != otd[i]) {
            cot++;
            if (ind[i] == otd[i] - 1) s = i;
            if (ind[i] == otd[i] + 1) t = i;
        }
    }

    if (cot != 0 && cot != 2) {
        std::cout << "No\n";
        exit(0);
    }

    if (cot == 0) s = t = 1;
    if (!s || !t) {
        std::cout << "No\n";
        exit(0);
    }

    for (int i = 1; i <= n; i++)
        std::sort(G[i].begin(), G[i].end());

    dfs(s);
    while (!ans.empty()) {
        std::cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}
