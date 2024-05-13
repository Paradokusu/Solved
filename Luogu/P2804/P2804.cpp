#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 7;
constexpr int MOD = 92084931;

int n, m;
int a[N], b[N];
i64 ans, sum[N];

void csort(int l, int r) {
    if (l == r)
        return;
    
    int mid = (l + r) >> 1;
    csort(l, mid);
    csort(mid + 1, r);

    int cnt = l - 1;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (sum[i] >= sum[j])
            b[++cnt] = sum[i++];
        else {
            b[++cnt] = sum[j++];
            ans += mid - i + 1;
            ans %= MOD;
        }
    }

    while (i <= mid)
        b[++cnt] = sum[i++];
    while (j <= r)
        b[++cnt] = sum[j++];
    
    for (int i = l; i <= r; i++)
        sum[i] = b[i];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] -= m;
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
        if (sum[i] > 0)
            ans++;
    
    csort(1, n);

    printf("%lld\n", ans % MOD);
    return 0;
}
