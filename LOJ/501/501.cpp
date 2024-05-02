#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5007;

i64 n, tot;
i64 a[N], b[N];
bool flg;

bool judge(i64 n) {
    while (n % 2 == 0)
        n /= 2;
    
    if (n == 1)
        return 1;
    
    return 0;
}

i64 cnt, top;

void dfs(i64 n) {
    /* 要么可选要么必选，必选方案数 2^t - 1 否则 2^t，考虑使用 1 2 3 构造，把 n 拆分为 2^t 和 2^t - 1 的乘积 */

    if (judge(n)) {
        cnt = 0;

        while (n % 2 == 0) {
            cnt++;
            n /= 2;
        }

        flg = 1;
        return;
    }

    i64 t = 4, l = 2;

    while (t - 1 <= n) {
        if (n % (t - 1) == 0) {
            top++;
            b[top] = l;
            dfs(n / (t - 1));

            if (flg)
                return;
            
            top--;
        }

        t <<= 1;
        l++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n;

    if (n == 1) {
        std::cout << "1\n1\n";
        return 0;
    }

    dfs(n);

    if (!flg) {
        std::cout << "qnq\n";
        return 0;
    }

    a[tot = 1] = 1;
    i64 now = 3;

    for (i64 i = 1; i <= top; i++) {
        i64 k = b[i];

        while (k) {
            a[++tot] = now;
            k--;
        }

        if (now == 1)
            now = 3;
        else
            now = 1;
    }

    while (cnt) {
        a[++tot] = 2;
        cnt--;
    }

    a[++tot] = now;
    std::cout << tot << "\n";

    for (int i = 1; i <= tot; i++)
        std::cout << a[i] << " ";
    
    std::cout << "\n";
    return 0;
}
