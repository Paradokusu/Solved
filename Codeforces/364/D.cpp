#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

std::random_device rdv;
std::mt19937 myrand(rdv());

int n, top;
i64 ans, a[N], prime[N];

std::map<int, int> cot;

void solve(i64 val) {
    i64 tv = val;
    std::vector<i64> v;
    for (i64 i = 1; i * i <= val; i++) {
        if (val % i == 0) {
            v.push_back(i);
            if (i != val / i)
                v.push_back(val / i);
        }
    }

    top = 0;
    cot.clear();
    std::sort(v.begin(), v.end(), std::greater<i64>());

    for (i64 i = 2; i * i <= val; i++) {
        if (val % i == 0) {
            prime[++top] = i;
            while (val % i == 0)
                val /= i;
        }
    }

    if (val != 1) prime[++top] = val;
    for (int i = 1; i <= n; i++) {
        cot[std::__gcd(tv, a[i])]++;
    }
    for (int j = 1; j <= top; j++) {
        for (auto i : v) {
            if (i % prime[j] == 0) {
                cot[i / prime[j]] += cot[i];
            }
        }
    }

    for (auto i : v) {
        if (cot[i] >= (n + 1) / 2)
            ans = std::max(ans, i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    int T = 10;
    while (T--) {
        int ps = myrand() % n + 1;
        solve(a[ps]);
    }

    printf("%lld\n", ans);
    return 0;
}
