#include <bits/stdc++.h>

using u64 = unsigned long long;

constexpr int N = 2e5 + 7;

std::random_device rdv;
std::mt19937_64 myrand(rdv());

int m, n;
u64 ans;
u64 a[N], b[N], c[N];   // a: 前缀异或和；b: 第 i 个位置是否赋值过；c: 最后减去全 0 区间贡献的辅助数组
std::map<u64, std::pair<u64, u64>> mp;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        u64 l, r, val;
        std::cin >> l >> r;
        val = myrand();
        a[l + 1] ^= val;
        a[r + 1] ^= val;    // 差分异或区间
        b[l]++;
        b[r + 1]--;
    }

    for (int i = 1; i <= n; i++) b[i] += b[i - 1];  // 差分前
    for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];  // 同上
    for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];  // 计算前缀异或和
    for (int i = 1; i <= n; i++) {
        std::pair<u64, u64> now = mp[a[i]];
        now.first++;
        now.second += i - 1;
        mp[a[i]] = now;
        ans += now.first * i - now.second;  // 计算贡献
    }

    for (int i = 1; i <= n; i++) {
        if (!b[i]) c[i] = c[i - 1] + 1;
        else c[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        ans -= c[i] * (c[i] + 1) / 2;   // 减去全 0 区间贡献

    printf("%llu\n", ans);
    return 0;
}
