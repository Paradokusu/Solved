#include <bits/stdc++.h>

int n, a;
long long ans;

int main() {
    scanf("%d", &n);
    std::priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        a -= i; // 套路做法？转为非严格
        q.push(a);
        if (a < q.top()) {
            q.push(a);
            ans += q.top() - a;
            q.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}
