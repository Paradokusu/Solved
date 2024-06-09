#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

constexpr int N = 10000 + 7;
constexpr u64 P = 19260817;
constexpr u64 B = 131;
constexpr u64 O = 0x7fffffff;

int n, ans = 1;
u64 myhash[N];
char s[N];

u64 gethash(char s[]) {
    int len = strlen(s);
    u64 res = 0;
    for (int i = 0; i < len; i++) {
        res = res * B + (u64) s[i];
    }
    return res & O;
}

int main() {
    freopen("ex.in", "r", stdin);
    freopen("ex.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %s", s);
        myhash[i] = gethash(s);
    }

    sort(myhash + 1, myhash + n + 1);
    for (int i = 1; i <= n - 1; i++) {
        if (myhash[i] != myhash[i + 1])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
