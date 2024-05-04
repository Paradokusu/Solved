#include <bits/stdc++.h>

constexpr int N = 1e4 + 7;
constexpr int M = 2e6 + 7;
const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {0, 0, 1, 0, -1};

int n, m, p, T;
int cot, k;
char a[N][N];
int dis[N][N], b[N][N], fa[N];
int dep[M], f[M][20], t[M][20];
bool usd[M], vis[N][N];

int tot, head[M], nxt[M], to[M], val[M];
void addedge(int u, int v, int w) {
	to[tot] = v;
	val[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot++;
}

struct edge {
    int u, v, w;
} e[M];

struct node {
    int x, y;
} qu[N];

std::queue<node> q;

bool cmp(const edge &x, const edge &y) {
    return x.w < y.w;
}

int find(int x) {
    if (fa[x] != x)
        return fa[x] = find(fa[x]);
    
    return fa[x];
}

void bfs() {
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.x, y = now.y;
        vis[x][y] = 1;
        
        for (int i = 1; i <= 4; i++) {
            int fx = x + dx[i];
            int fy = y + dy[i];

            if (fx < 1 || fx > n || fy < 1 || fy > m || a[fx][fy] == '#' || vis[fx][fy])
                continue;
            
            vis[x][y] = 1;

            if (!b[fx][fy]) {
                b[fx][fy] = b[x][y];
                dis[fx][fy] = dis[x][y] + 1;
                q.push({fx, fy});
                continue;
            }

            if (b[fx][fy] != b[x][y]) {
                e[++cot].u = b[fx][fy];
                e[cot].v = b[x][y];
                e[cot].w = dis[fx][fy] + dis[x][y];
            }
        }
    }
}

void dfs(int x, int lst, int depth) {
    dep[x] = depth;
    usd[x] = 1;

    for (auto i = head[x]; i; i = nxt[i]) {
        int v = to[i];

        if (v == lst)
            continue;
        
        f[v][0] = x;
        t[v][0] = val[i];
        dfs(v, x, depth + 1);
    }
}

void dp() {
    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= p; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            t[i][j] = std::max(t[i][j - 1], t[f[i][j - 1]][j - 1]);
        }
}

int lca(int x, int y) {
    if (find(fa[x]) != find(fa[y]))
        return -1;
    
    int res = 0;

    if (dep[x] < dep[y])
        std::swap(x, y);
    
    for (int i = 18; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) {
            res = std::max(res, t[x][i]);
            x = f[x][i];
        }
    
    if (x == y)
        return res;
    
    for (int i = 19; i >= 0; i--) {
        if (f[x][i] == f[y][i] || !f[x][i] || !f[y][i])
            continue;
        
        res = std::max({res, t[x][i], t[y][i]});
        x = f[x][i];
        y = f[y][i];
    }

    res = std::max({res, t[x][0], t[y][0]});
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m >> p >> T;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];

    for (int i = 1; i <= p; i++) {
        int x, y;
        std::cin >> x >> y;
        b[x][y] = i;
        q.push({x, y});
    }

    bfs();

    for (int i = 1; i <= p; i++)
        fa[i] = i;
    
    std::sort(e + 1, e + cot + 1, cmp);

    for (int i = 1; i <= cot; i++) {
        int fx = find(e[i].u), fy = find(e[i].v);

        if (fx == fy)
            continue;
        
        fa[fy] = fx;
        k++;

        addedge(e[i].u, e[i].v, e[i].w);
        addedge(e[i].v, e[i].u, e[i].w);
        
        if (k == p - 1)
            break;
    }

    for (int i = 1; i <= p; i++)
        if (!usd[i])
            dfs(i, 0, 1);
    
    dp();

    while (T--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << lca(x, y) << "\n";
    }

    return 0;
}
