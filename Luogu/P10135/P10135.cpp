#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, tot;
int a[N], ind[N], lf[N];    // lf[i]: 以 i 为根的子树有 lf_i 个节点是子节点
int dp[N];  // dp[i]: 以 i 为根的子树最多可以拿到多少瓶药水
std::vector<int> G[N];

void dfs(int u, int fa) {
    for (size_t i = 0; i < G[u].size(); i++) {
        int v = G[u][i];

        if (v == fa)
            continue;
        
        dfs(v, u);
        dp[u] += dp[v];
        lf[u] += lf[v];
    }

    dp[u] = std::min(dp[u], lf[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        ind[u]++, ind[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 2; i <= n; i++) {
        if (ind[i] == 1) {
            tot++;
            lf[i] = 1;
        }
    }

    for (int i = 1; i <= tot; i++) {
        dp[a[i]]++;
    }

    dfs(1, 0);

    std::cout << dp[1] << "\n";
    return 0;
}
