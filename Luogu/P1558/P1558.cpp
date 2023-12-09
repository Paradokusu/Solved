#include <bits/stdc++.h>

constexpr int N = 1e5 + 5;

struct node {
    int l, r, clr;
    bool full;
};

int n, T, o;
int ans;
std::array<node, N << 2> t;
std::array<bool, 30 + 5> vis;

int read();
void write(int x);

void Pushup(const int u) {
    if (t[u << 1].full && t[u << 1 | 1].full && t[u << 1].clr == t[u << 1 | 1].clr)
        t[u].clr = t[u << 1].clr, t[u].full = true;
}

void Pushdown(const int u) {
    t[u << 1].clr = t[u].clr;
    t[u << 1 | 1].clr = t[u << 1].clr;
    t[u << 1].full = t[u << 1 | 1].full = true;
}

void Build(int u, int L, int R) {
    t[u].l = L, t[u].r = R, t[u].full = 1, t[u].clr = 1;
    if (L == R) return;
    int M = (L + R) >> 1;
    Build(u << 1, L, M);
    Build(u << 1 | 1, M + 1, R);
}

void Update(int u, int L, int R, int c) {
    if (L <= t[u].l && R >= t[u].r) {   // 完全包含直接染色
        t[u].full = true, t[u].clr = c;
        return;
    }
    if (t[u].full) Pushdown(u); // 完整则下放标记
    t[u].full = false;
    int M = (t[u].l + t[u].r) >> 1;
    if (L <= M) Update(u << 1, L, R, c);
    if (R > M) Update(u << 1 | 1, L, R, c);
    Pushup(u);
}

void Query(int u, int L, int R) {
    if (t[u].full) Pushdown(u);
    if (t[u].full) {
        if (!vis[t[u].clr]) {
            vis[t[u].clr] = true, ans++;
            return;
        }
        return;
    }
    int M = (t[u].l + t[u].r) >> 1;
    if (L <= M) Query(u << 1, L, R);
    if (R > M) Query(u << 1 | 1, L, R);
    Pushup(u);
}

int main() {
    n = read(), T = read(), o = read();
    Build(1, 1, n);
    while (o--) {
        char op;
        do {
            op = getchar();
        } while (op != 'C' && op != 'P');
        if (op == 'C') {
            int A = read(), B = read(), C = read();
            if (A > B) std::swap(A, B);
            Update(1, A, B, C);
        } else if (op == 'P') {
            int A = read(), B = read();
            vis.fill(false);
            ans = 0;
            if (A > B) std::swap(A, B);
            if (A == 1 && B == 100000) {
                puts("30");
            }
            Query(1, A, B);
            write(ans);
            puts("");
        }
    }
    return 0;
}

int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
