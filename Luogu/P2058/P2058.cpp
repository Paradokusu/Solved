#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 50;

int n, ans;
int v[N];

struct node {
    int t, na;

    node(int a, int b) {
        t = a, na = b;
    }
};

deque<node> q;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int t, k, p;
        scanf("%d %d", &t, &k);

        for (int j = 1; j <= k; j++) {
            scanf("%d", &p);
            if (!v[p]) ans++;
            v[p]++;
            q.push_back(node(t, p));
        }

        while (t - q.front().t >= 86400) {  // 超出时间范围，滑动窗口
            v[q.front().na]--;
            if (!v[q.front().na]) ans--;
            q.pop_front();  // 从前往后弹出队列
        }

        printf("%d\n", ans);
    }

    return 0;
}
