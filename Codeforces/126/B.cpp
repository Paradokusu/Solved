#include <bits/stdc++.h>

constexpr int N = 1000000 + 7;

int n, mxlen;
int nex[N];
char s[N];

void check(int x) {
    if (x == 0) {
        printf("Just a legend\n");
        exit(0);
    }
}

int main() {
    scanf(" %s", s + 1);
    n = strlen(s + 1);

    nex[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1])
            j = nex[j];
        if (s[j + 1] == s[i])
            j++;
        nex[i] = j;
        if (i != n)
            mxlen = std::max(mxlen, nex[i]);
    }

    int p = nex[n];
    check(p);
    
    for (p = nex[n]; p > mxlen; p = nex[p]);
    check(p);

    for (int i = 2; i < n; i++) {
        if (p == nex[i]) {
            for (int j = i - nex[i] + 1; j <= i; j++)
                printf("%c", s[j]);
            printf("\n");
            exit(0);
        }
    }

    return 0;
}
