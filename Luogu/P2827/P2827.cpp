#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 7;
constexpr int inf = numeric_limits<int>::max();

int n, m, q;
int u, v, t;
int a[N];
queue<int> q1, q2, q3;

int findmax() {
    int p0, p1, p2, p3;

    if (!q1.empty())
        p1 = q1.front();
    else
        p1 = -inf;

    if (!q2.empty())
        p2 = q2.front();
    else
        p2 = -inf;
    
    if (!q3.empty())
        p3 = q3.front();
    else
        p3 = -inf;
    
    if (p1 > p2 && p1 > p3) {
        p0 = p1;
        q1.pop();
    } else if (p2 > p3) {
        p0 = p2;
        q2.pop();
    } else {
        p0 = p3;
        q3.pop();
    }

    return p0;
}

int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &q, &u, &v, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    sort(a + 1, a + n + 1, greater<int>());
    
    for (int i = 1; i <= n; i++)
        q1.push(a[i]);
    
    for (int i = 1; i <= m; i++) {
        int x = findmax() + q * (i - 1);    // 蚯蚓原长
        if (i % t == 0)
            printf("%d ", x);
        
        int y = (long double) x * u / v;    // 第一只
        x -= y; // 第二只
        y -= q * i;
        q2.push(y);
        x -= q * i;
        q3.push(x);
    }
    
    printf("\n");
    for (int i = 1; i <= n + m; i++) {
        int x = findmax() + q * m;
        if (i % t == 0)
            printf("%d ", x);
    }

    printf("\n");
    return 0;
}
