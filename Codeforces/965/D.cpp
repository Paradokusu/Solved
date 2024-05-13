#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int w, l;
int a[N], sum[N];

int main() {
    scanf("%d %d", &w, &l);
    for (int i = 1; i < w; i++) {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }
    
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < w - l; i++)
        ans = std::min(sum[i + l] - sum[i], ans);
    
    printf("%d\n", ans);
    return 0;
}
