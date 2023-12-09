#include <bits/stdc++.h>

constexpr int N = 1e5 + 5;
constexpr int INF = 1e9;

int n, m;
std::array<int, N * 4 + 5> Min;

void build(int u, int L, int R) {
    if (L == R) {
        std::cin >> Min[u];
        return;
    }
    int M = (L + R) >> 1;
    build(u << 1, L, M);
    build((u << 1) + 1, M + 1, R);
    Min[u] = std::min(Min[u << 1], Min[(u << 1) + 1]);
}

int query(int u, int l, int r, int x, int y) {
    if (x <= l && y >= r) return Min[u];
    else if (r < x || y < l) return 0;

    int M = (l + r) >> 1;
    int lM = INF, rM = INF;
    if (x <= M) lM = query(u << 1, l, M, x, y);
    if (y > M) rM = query((u << 1) + 1, M + 1, r, x, y);
    return std::min(lM, rM);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << query(1, 1, n, x, y) << " ";
    }
    return 0;
}
