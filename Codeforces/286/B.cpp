#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;

int n;
int a[N << 1];

int main() {
    scanf("%d", &n);
    std::iota(a + 1, a + n + 1, 1);

    int p = 0;
    for (int k = 2; k <= n; k++) {
        p++;
        if (n % k)
            a[p + n] = a[p + n - n % k];
        
        for (int i = n / k; i; i--)
            a[p + k * i] = a[p + k * i - k];
    }

    for (int i = p + 1; i <= p + n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
