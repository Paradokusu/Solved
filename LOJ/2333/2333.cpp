#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3007;

int n, m, k;
int a, b, c;
int s[N];

i64 ans, tot;
std::priority_queue<int> q;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m >> k;
    std::cin >> a >> b >> c;
    std::cin >> tot;

    for (int i = 1; i <= m; i++)
        std::cin >> s[i];
    
    s[m + 1] = n + 1;
    k -= m;

    for (int i = 1; i <= m; i++) {
        i64 loc = s[i], ret = tot - (1ll * s[i] - 1) * b;

        if (ret < 0)
            break;
        
        i64 now = s[i] + ret / a;
        ans += std::min(now, 1ll * s[i + 1] - 1) - s[i] + 1;
        int tmp = k;

        while (tmp && ret >= 0) {
            tmp--;
            i64 d = (now + 1 - loc) * c;
            ret -= d;

            if (ret < 0)
                break;
            
            loc = now + 1;

            if (loc >= s[i + 1])
                break;
            
            now = loc + ret / a;
            q.push(-(std::min(now, 1ll * s[i + 1] - 1) - loc + 1));

            while (q.size() > k)
                q.pop();
        }
    }

    while (!q.empty()) {
        ans -= q.top();
        q.pop();
    }

    std::cout << ans - 1 << "\n";
    return 0;
}

/*
300 8 16
345678901 123456789 234567890
12345678901
1
10
77
82
137
210
297
300
*/
