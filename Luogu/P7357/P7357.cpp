#include <bits/stdc++.h>

constexpr int N = 5e6 + 7;
constexpr int inf = std::numeric_limits<int>::max();

struct node {
    int son[30];
    bool exist;
};

int n;
char s[N];

struct trie {
    int t0t = 1;
    node ch[N];

    void insert(char x[]) {
        int u = 1, len = strlen(x + 1);
        for (int i = 1; i <= len; i++) {
            int v = x[i] - 'a' + 1;
            if (!ch[u].son[v])
                ch[u].son[v] = ++t0t;
            u = ch[u].son[v];
        }
        ch[u].exist = 1;
    }
} tr;

int ans;
int f[N];

void dfs(int o) {
    int dim = 0, mxs = 0, mxe = 0;
    for (int i = 1; i <= 26; i++) {
        if (tr.ch[o].son[i]) {
            int v = tr.ch[o].son[i];
            dim += tr.ch[v].exist;
            dfs(v);
            if (!tr.ch[v].exist)
                f[v] = 0;
            
            if (f[v] > mxs) {
                mxe = mxs;
                mxs = f[v];
            } else if (f[v] > mxe) {
                mxe = f[v];
            }
        }
    }

    if (dim == 0) { // none
        f[o] = tr.ch[o].exist;
        ans = std::max(ans, f[o]);
    } else if (dim == 1) {  // father-one of the sons
        f[o] = mxs + tr.ch[o].exist;
        ans = std::max(ans, f[o]);
        if (!tr.ch[o].exist)
            f[o] = 0;
    } else {    // brothers
        f[o] = mxs + dim - 1 + tr.ch[o].exist;
        ans = std::max(ans, mxs + mxe + dim - 2 + tr.ch[o].exist);
        if (!tr.ch[o].exist)
            f[o] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %s", s + 1);
        int len = strlen(s + 1);
        std::reverse(s + 1, s + len + 1);
        // for (int j = 1; j <= len / 2; j++)
        //     std::swap(s[j], s[len - j + 1]);
        tr.insert(s);
    }
    dfs(1);
    std::cout << ans << "\n";
    return 0;
}
