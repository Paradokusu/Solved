#include <bits/stdc++.h>

constexpr int N = 30007;
constexpr int M = 300007;

int n, ans;
bool ok[N];
std::string s[N];

struct trie {
    int tot, ch[M][30];
    int ind[30], e[30][30];
    bool pf[M];

    void insert(std::string str) {
        int u = 1, len = str.size();
        for (int i = 0; i < len; i++) {
            int v = str[i] - 'a';
            if (!ch[u][v]) ch[u][v] = ++tot;
            u = ch[u][v];
        }
        pf[u] = 1;  // 前缀标记
    }

    void topo() {
        std::queue<int> q;
        for (int i = 0; i < 26; i++)
            if (!ind[i])
                q.push(i);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < 26; v++) {
                if (e[u][v]) {
                    ind[v]--;
                    if (!ind[v])
                        q.push(v);
                }
            }
        }
    }

    bool find(std::string str) {
        int u = 1, len = str.size();
        memset(ind, 0, sizeof(ind));
        memset(e, 0, sizeof(e));
        for (int i = 0; i < len; i++) {
            if (pf[u]) return 0;    // 是其他字符串的前缀
            int v = str[i] - 'a';
            for (int j = 0; j < 26; j++) {
                if (v != j && ch[u][j] && !e[v][j]) {
                    e[v][j] = 1;
                    ++ind[j];
                }
            }
            u = ch[u][v];
        }

        topo();
        for (int i = 0; i < 26; i++)
            if (ind[i])
                return 0;
        return 1;
    }
} tr;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n;
    tr.tot = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        tr.insert(s[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (tr.find(s[i])) {
            ans++;
            ok[i] = 1;
        }
    }

    std::cout << ans << "\n";
    for (int i = 1; i <= n; i++)
        if (ok[i])
            std::cout << s[i] << "\n";
    return 0;
}
