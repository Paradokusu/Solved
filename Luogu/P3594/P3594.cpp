#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 7;

int n, p, d;
i64 q[N], w[N], sum[N];

int main() {
    scanf("%d %d %d", &n, &p, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
        sum[i] = sum[i - 1] + w[i];
    }

    int ans = d, l = 1;
    int head = 0, tail = 0;
    q[tail] = d;

    for (int i = d + 1; i <= n; i++) {  // 维护 max(sum[x] + sum[x - d + 1])
        while (head <= tail && sum[i] - sum[i - d] > sum[q[tail]] - sum[q[tail] - d])
            tail--;
        q[++tail] = i;
        while (head <= tail && sum[i] - sum[l - 1] - sum[q[head]] + sum[q[head] - d] > p) {
            l++;
            while (head <= tail && q[head] - d + 1 < l)
                head++;
        }
        ans = std::max(ans, i - l + 1);
    }

    printf("%d\n", ans);
    return 0;
}
