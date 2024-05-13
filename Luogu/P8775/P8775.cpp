#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n, x;
i64 a[N], sum[N];

bool check(int p) {
    for (int i = p; i < n; i++)
        if (sum[i] - sum[i - p] < 2 * x)
            return 0;
    return 1;
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", r);
    return 0;
}
