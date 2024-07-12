#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;
constexpr int C = 1e6;
constexpr i64 inf = std::numeric_limits<i64>::max();
constexpr double MAX_TIME = 1;

int n;
i64 ans = inf;
i64 a[N], pri[C / 10];

std::set<i64> s;
std::bitset<C + 1> p;

std::random_device rdv;
std::mt19937 myrand(rdv());

void init() {   // 埃筛预处理出 1e6 素数
    for (int i = 2; i <= C; i++)
        p[i] = 1;   
    for (int i = 2; i <= C; i++) {
        if (!p[i]) continue;
        pri[++pri[0]] = i;
        for (i64 j = (i64) i * i; j <= C; j += i)
            p[j] = 0;
    }
}

void solve(i64 x) { // 分解质因数后插入
    for (int i = 1; i <= pri[0]; i++) {
        if (x == 1) break;
        if (x % pri[i] == 0) {
            x /= pri[i];
            s.insert(pri[i]);
        }
        while (x % pri[i] == 0) x /= pri[i];
    }
    if (x > 1)
        s.insert(x);
}

int gen(int x, int y) {
    int res = 0;
    for (int i = 1; i <= 9; i++)
        res = res * 10 + myrand() % 10;
    return x + res % (y - x + 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    int T = 50;
    while (T--) {
        int ps = gen(1, n);
        // delta = 0/1/-1
        solve(a[ps] + 1);
        solve(a[ps]);
        if (a[ps] > 1)
            solve(a[ps] - 1);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        i64 sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < *it) sum += *it - a[i];
            else sum += std::min(a[i] % (*it), (*it) - a[i] % (*it));
        }
        ans = std::min(ans, sum);
    }

    std::cout << ans << "\n";
    return 0;
}
