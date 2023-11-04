#include <bits/stdc++.h>

int read();
void write(int x);

void solve() {
    int n = read();
    std::vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        a[i] = read();

    int g = a[1];
    for (int i = 2; i <= n; i++)
        g = std::__gcd(g, a[i]);
    
    if (g == 1) {
        puts("0");
        return;
    } else {
        if (std::__gcd(g, std::__gcd(a[n], n)) == 1) {
            puts("1");
            return;
        } else {
            if (std::__gcd(g, std::__gcd(a[n - 1], n - 1)) == 1) {
                puts("2");
                return;
            } else {
                puts("3");
                return;
            }
        }
    }
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}