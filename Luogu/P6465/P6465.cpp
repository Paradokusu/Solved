#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 7;

int n, m, l, r;
int a[N], cnt[N];
long long ans;

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    ans = 0;
    int r = 0;
    for (int l = 1; l <= n; l++) {
        while ((r < l || a[r] != a[r + 1]) && r < n)
            if (++r >= l + m - 1)
                cnt[a[r]]++;
        ans += max(0, r - (l + m - 1) + 1 - cnt[a[l]]);
        if (r >= l + m - 1)
            cnt[a[l + m - 1]]--;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
