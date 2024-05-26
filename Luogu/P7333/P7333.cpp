#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n;
int a[N << 2];
int lg[N << 2], st[20][N << 2];

int query(int l, int r) {
    int p = lg[r - l + 1];
    return max(st[p][l], st[p][r - (1 << p) + 1]);
}

bool check(int t, int i, int x) {
    return max(query(i - t, i - 1), query(i + 1, i + t)) >= x;
}

int out(int x, int i) {
    int res = -1, l = 1, r = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, i, x)) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + 2 * n] = a[i + n] = a[i];
    }

    lg[0] = -1;
    for (int i = 1; i <= n * 3; i++) {
        lg[i] = lg[i >> 1] + 1;
        st[0][i] = a[i];
    }
    
    // a[n + 1] = a[1], b[n + 1] = b[1];

    for (int j = 1; (1 << j) <= n * 3; j++) {
        for (int i = 1; i + (1 << j) - 1 <= 3 * n; i++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }

    for (int i = 1, inp; i <= n; i++) {
        scanf("%d", &inp);
        printf("%d ", out(inp, i + n));
    }

    return 0;
}
