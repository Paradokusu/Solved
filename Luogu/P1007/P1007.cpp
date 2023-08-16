#include <bits/stdc++.h>

using namespace std;

int l, n, pos;
int maxt, mint;

int main() {
    scanf("%d", &l);
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pos);
        maxt = max(maxt, max(l - pos + 1, pos));
        mint = max(mint, min(l - pos + 1, pos));
    }

    printf("%d %d\n", mint, maxt);
    return 0;
}
