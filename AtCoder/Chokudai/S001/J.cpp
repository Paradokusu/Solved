#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 7;

int n;
int a[N], b[N];
i64 ans;

void cmerge(int l, int mid, int r) {
    if (l == r) return;
    if (l + 1 == r) {
        if (a[l] > a[r]) {
            ans++;
            swap(a[l], a[r]);
        }
        return;
    }

    cmerge(l, (l + mid) >> 1, mid);
    cmerge(mid + 1, (mid + 1 + r) >> 1, r);

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (j > r || (i <= mid && a[i] <= a[j]))
            b[k] = a[i++];
        else {
            b[k] = a[j++];
            ans += (mid - i + 1);
        }
    }

    for (int k = l; k <= r; k++)
        a[k] = b[k];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    cmerge(1, (1 + n) >> 1, n);
    printf("%lld\n", ans);
    return 0;
}
