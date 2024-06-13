#include <bits/stdc++.h>

constexpr int N = 100000 + 7;

int n, k;
char a[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf(" %s", a + 1);

    int ansa = 0, ansb = 0;

    int l = 0, cot = 0;
    for (int r = 1; r <= n; r++) {
        if (a[r] == 'a')
            cot++;
        while (cot > k && l < r) {
            l++;
            if (a[l] == 'a')
                cot--;
        }
        if (r - l > ansa) ansa = std::max(ansa, r - l);
    }

    l = 0, cot = 0;
    for (int r = 1; r <= n; r++) {
        if (a[r] == 'b')
            cot++;
        while (cot > k && l < r) {
            l++;
            if (a[l] == 'b')
                cot--;
        }
        if (r - l > ansb) ansb = std::max(ansa, r - l);
    }

    printf("%d\n", std::max(ansa, ansb));
    return 0;
}
