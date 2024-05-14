#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n, k;
i64 sum[N], dp[N][2];
deque<int> q;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1, inp; i <= n; i++) {
        scanf("%d", &inp);
        sum[i] = sum[i - 1] + inp;
    }

    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        while (!q.empty() && q.front() < i - k)
            q.pop_front();
        dp[i][1] = dp[q.front()][0] + (sum[i] - sum[q.front()]);
        while (!q.empty() && (dp[q.back()][0] - sum[q.back()] < dp[i][0] - sum[i]))
            q.pop_back();
        q.push_back(i);
    }

    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}
