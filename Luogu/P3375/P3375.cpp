#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;

int n, m;
int j, nex[N];
char a[N], b[N];

int main() {
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);

    n = strlen(a + 1);
    m = strlen(b + 1);

    for (int i = 2; i <= m; i++) {
        while (j && b[i] != b[j + 1])
            j = nex[j];
        if (b[j + 1] == b[i])
            j++;
        nex[i] = j;
    }

    j = 0;
    for (int i = 1; i <= n; i++) {
        while (j && a[i] != b[j + 1])
            j = nex[j];
        if (b[j + 1] == a[i])
            j++;
        
        if (j == m) {
            printf("%d\n", i - m + 1);
            j = nex[j];
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", nex[i]);
    }
    return 0;
}
