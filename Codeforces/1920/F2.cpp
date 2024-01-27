#include <bits/stdc++.h>

constexpr int N = 3e5 + 7;
constexpr int inf = 1e9;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, q, linei, linej;
int par[N * 2], ans[N];
std::string A[N];
std::queue<std::pair<int, int>> que;
std::vector<int> dist[N];
std::vector<std::array<int, 3>> edges;
std::set<int> S[N * 2];

int enc(int i, int j, bool crs) {
    return i * m + j + crs * n * m;
}

bool inGrid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int getR(int i) {
    return i == par[i] ? i : par[i] = getR(par[i]);
}

void merge(int a, int b, int w) {
    a = getR(a), b = getR(b);

    if (a == b) return;
    if (S[a].size() > S[b].size()) std::swap(S[a], S[b]);

    for (auto i : S[a]) {
        if (S[b].count(i)) {
            ans[i] = w;
            S[b].erase(i);
        } else {
            S[b].insert(i);
        }
    }

    par[a] = b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];

        for (int j = 0; j < m; j++) {
            dist[i].push_back(inf);

            if (A[i][j] == 'v') {
                dist[i][j] = 0;
                que.push({i, j});
            }

            if (A[i][j] == '#') {
                linei = i;
                linej = j;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        S[enc(x, y, 0)].insert(i);
        S[enc(x, y, 1)].insert(i);
    }

    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            int fi = i + dx[dir], fj = j + dy[dir];

            if (inGrid(fi, fj) && dist[i][j] + 1 < dist[fi][fj]) {
                dist[fi][fj] = dist[i][j] + 1;
                que.push({fi, fj});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 2; dir++) {
                int fi = i + dx[dir], fj = j + dy[dir];

                if (inGrid(fi, fj) && A[i][j] != '#' && A[fi][fj] != '#') {
                    int w = std::min(dist[i][j], dist[fi][fj]);

                    if (i == linei && fi == linei - 1 && j > linej) {
                        edges.push_back({w, enc(i, j, 0), enc(fi, fj, 1)});
                        edges.push_back({w, enc(i, j, 1), enc(fi, fj, 0)});
                    } else {
                        edges.push_back({w, enc(i, j, 0), enc(fi, fj, 0)});
                        edges.push_back({w, enc(i, j, 1), enc(fi, fj, 1)});
                    }
                }
            }
        }
    }

    std::sort(edges.begin(), edges.end(), std::greater<std::array<int, 3>>());
    std::iota(par, par + N * 2, 0);

    for (auto [w, u, v] : edges) {
        merge(u, v, w);
    }

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}

