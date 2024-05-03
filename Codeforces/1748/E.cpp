#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;
constexpr int MOD = 1e9 + 7;

int n, m;
int L[N], R[N], fa[N];
int top, stc[N];
i64 f[N << 8], w[N];

void build(int n) {
    top = 0;

    for (int i = 0; i <= n; i++)
        L[i] = R[i] = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];

        while (top && w[stc[top]] < w[i])
            L[i] = stc[top--];
        
        fa[i] = stc[top];
        fa[L[i]] = i;

        if (fa[i])
            R[fa[i]] = i;
        
        stc[++top] = i;
    }
}

int rg(int x, int y) {
    return (x - 1) * m + y;
}

i64 dp(int x, int k) {
    if (k < 1)
        return 0;
    
    if (!L[x] && !R[x])
        return k;
    
    if (f[rg(x, k)] != -1)
        return f[rg(x, k)];
    
    i64 ans = 0;

    if (L[x] && R[x])
        ans = (dp(x, k - 1) + dp(L[x], k - 1) * dp(R[x], k)) % MOD;
    else if (L[x])
        ans = (dp(x, k - 1) + dp(L[x], k - 1)) % MOD;
    else if (R[x])
        ans = (dp(x, k - 1) + dp(R[x], k)) % MOD;
    
    return f[rg(x, k)] = ans;
}

void solve() {
    std::cin >> n >> m;

    for (int i = 1; i <= n * m; i++)
        f[i] = -1;

    build(n);

    int rt, mxn = 0;

    for (int i = 1; i <= n; i++) {
        if (w[i] > mxn) {
            mxn = w[i];
            rt = i;
        }
    }

    std::cout << dp(rt, m) << "\n";
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
