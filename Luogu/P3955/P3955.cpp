#include <bits/stdc++.h>

using namespace std;
const int N = 1050;
const int MOD[9] = {0, 10, 100, 1000, 10000, 100000, 1000000, 1000000, 10000000};

int n, q, x, y;

int a[N];

int work() {
    for (int i = 1; i <= n; i++) {
        if (a[i] % MOD[x] == y)
            return a[i];
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", work());
    }

    return 0;
}
