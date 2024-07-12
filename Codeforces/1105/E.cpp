#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;
constexpr int M = 50;
constexpr double MAX_TIME = 1.95;

int n, m;
int cnt, top, t0t;
int head[N];

std::bitset<N> b[M];
std::bitset<M> f[M];
std::bitset<M> s;

std::map<std::string, int> mp;
int ans, a[N];

int count() {
    s.reset();
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int u = a[i];
        if (!(s & f[u]).count()) {
            s[u] = 1;
            res++;
        }
    }
    return res;
}

void simulateAnneal() {
    for (double T = 5000; T >= 1e-14; T *= 0.96) {
        int x = rand() % m + 1, y = rand() % m + 1;
        std::swap(a[x], a[y]);
        int cot = count();
        int dlt = cot - ans;
        std::swap(a[x], a[y]);
        if (dlt > 0) {
            ans = cot;
            std::swap(a[x], a[y]);
        } else if (std::exp(-dlt / T) * RAND_MAX <= rand())
            std::swap(a[x], a[y]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    srand(time(nullptr));

    std::cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        if (x == 1) {
            top++;
        } else {
            std::string s;
            std::cin >> s;
            if (mp.find(s) == mp.end()) mp[s] = ++t0t;
            b[mp[s]][top] = 1;
        }
    }

    for (int i = 1; i <= top; i++) {
        for (int j = 1; j < t0t; j++) {
            for (int k = j + 1; k <= t0t; k++)
                if (b[j][i] && b[k][i])
                    f[j][k] = f[k][j] = 1;
        }
    }

    for (int i = 1; i <= m; i++)
        a[i] = i;
    
    while ((double) std::clock() / CLOCKS_PER_SEC <= MAX_TIME)
        simulateAnneal();
    
    printf("%d\n", ans);
    return 0;
}
