#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;
constexpr int root = 0;

int n, q, cnt, opt[N], ans[N];
string str[N];

struct Question {
    string ip;
    int id;
} ques[N];

vector<int> del[N], add[N];

struct node {
    int son[2], end, times, tag;
    
    inline void Update(int val) { times += val, tag += val; }

    #define ls(x) t[x].son[0]
    #define rs(x) t[x].son[1]
    #define end(x) t[x].end
    #define times(x) t[x].times
    #define tag(x) t[x].tag
} t[N * 32];

inline void Pushdown(int id) {
    if (!ls(id)) ls(id) = ++cnt;
    if (!rs(id)) rs(id) = ++cnt;
    if (!tag(id)) return;
    if (!end(ls(id))) t[ls(id)].Update(tag(id));
    if (!end(rs(id))) t[rs(id)].Update(tag(id));
    tag(id) = 0;
}

inline void Modify(string s, int val) {
    int now = root, len = s.length();
    for (register int i = 0; i < len; i++) {
        Pushdown(now);
        now = t[now].son[s[i] - '0'];
    }
    end(now) += val, tag(now)++, times(now)++;
}

inline int Query(string s) {
    int now = root, len = s.length();
    for (register int i = 0; i < len; i++) {
        Pushdown(now);
        now = t[now].son[s[i] - '0'];
    }
    return times(now);
}

int main() {
	scanf("%d %d", &n, &q);
    for (register int i = 1; i <= n; i++) {
        char s[6];
        scanf("%s", s);
        cin >> str[i];
        
        if (s[0] == 'A')
            opt[i] = 1;
        else
            opt[i] = -1;
    }
    for (register int i = 1; i <= q; i++) {
        cin >> ques[i].ip;
        ques[i].id = i;
        
        int l, r;
        scanf("%d %d", &l, &r);
        del[l].push_back(i), add[r].push_back(i);
    }
    for (register int i = 1; i <= n; i++) {
        Modify(str[i], opt[i]);
        for (register int j = 0, tmp = del[i].size(); j < tmp; j++)
            ans[ques[del[i][j]].id] -= Query(ques[del[i][j]].ip);
        for (register int j = 0, tmp = add[i].size(); j < tmp; j++)
            ans[ques[add[i][j]].id] += Query(ques[add[i][j]].ip);
    }
    for (register int i = 1; i <= q; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
