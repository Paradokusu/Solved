#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100000 + 7;

int n;
int s[N];

int t0t, head[N];
struct edge {
    int nxt, to, val;
} e[N << 1];

void addedge(int x, int y, int z) {
    e[++t0t].nxt = head[x];
    e[t0t].to = y;
    e[t0t].val = z;
    head[x] = t0t;
}

void dfs(int u, int lst) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = e[i].val;
        if (v != lst) {
            s[v] = s[u] ^ w;
            dfs(v, u);
        }
    }
}

struct trie {
    int tot, ch[N * 31][2];

    void insert(int val) {
        int u = 0;
        for (int i = (1 << 30); i; i >>= 1) {
            int v = bool(val & i);  // 取出位
            if (!ch[u][v]) ch[u][v] = ++tot;
            u = ch[u][v];
        }
    }

    int find(int val) {
        int res = 0, u = 0;
        for (int i = (1 << 30); i; i >>= 1) {
            int v = bool(val & i);
            if (ch[u][!v]) {    // 按位贪心
                res += i;
                u = ch[u][!v];
            } else u = ch[u][v];
        }
        return res;
    }
} tr;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }

    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        tr.insert(s[i]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, tr.find(s[i]));
    
    printf("%d\n", ans);
    return 0;
}
