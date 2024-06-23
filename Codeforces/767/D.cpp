#include <bits/stdc++.h>

constexpr int N = 1e7 + 7;
 
struct node {
    int id, et;
} mkt[N];

bool cmp(const node &a, const node &b) {
    if (a.et == b.et) return a.id < b.id;
    return a.et < b.et;
}

int n, m, k;
int mxt;
int hme[N], ans[N], spr[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1, inp; i <= n; i++) {
        scanf("%d", &inp);
        mxt = std::max(mxt, inp);
        hme[inp]++;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &mkt[i].et);
        mkt[i].id = i;
        mxt = std::max(mxt, mkt[i].et);
    }

    std::sort(mkt + 1, mkt + m + 1, cmp);
    for (int i = mxt; i >= 0; i--) {
        if (hme[i] <= k) {
            spr[i] = k - hme[i];
        } else {
            if (i == 0) {
                printf("-1\n");
                exit(0);
            }

            hme[i - 1] += (hme[i] - k);
        }
    }

    int now = 1, cot = 0;
    for (int i = 0; i <= mxt; i++) {
        if (spr[i] > 0) {
            while (mkt[now].et < i && now <= m)
                now++;   // 过期不买
            while (spr[i] > 0 && now <= m) {
                ans[++cot] = mkt[now].id;
                spr[i]--;
                now++;
            }
        }
    }

    std::sort(ans + 1, ans + cot + 1);
    printf("%d\n", cot);
    for (int i = 1; i <= cot; i++)
        printf("%d ", ans[i]);
    return 0;
}
