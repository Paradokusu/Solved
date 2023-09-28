#include <bits/stdc++.h>

void solve() {
	int M;
    std::cin >> M;
    int N = 3;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    int INF = std::numeric_limits<int>::max();
    int ans = INF;
    for (int i = 0; i < N * M; i++) {
        for (int j = 0; j < N * M; j++) {
            for (int k = 0; k < N * M; k++) {
                if (i != j && i != k && j != k && S[0][i % M] == S[1][j % M] && S[1][j % M] == S[2][k % M]) {
                    ans = std::min(ans, std::max({i, j, k}));
                }
            }
        }
    }
    std::cout << (ans < INF ? std::to_string(ans) : "-1") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
