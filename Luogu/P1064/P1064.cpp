#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> mw(n + 1), mv(n + 1), f(n + 1);
    std::vector<std::vector<int>> fw(n + 1, std::vector<int>(3)), fv(n + 1, std::vector<int>(3));

    for (int i = 1; i <= m; i++) {
        int v, p, q;
        std::cin >> v >> p >> q;

        if (!q) {   // 主件
            mw[i] = v;
            mv[i] = v * p;
        } else {
            fw[q][0]++; // 附件数
            fw[q][fw[q][0]] = v;
            fv[q][fw[q][0]] = v * p;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= mw[i]; j--) {
            f[j] = std::max(f[j], f[j - mw[i]] + mv[i]);    // 单选主件
            if (j >= mw[i] + fw[i][1])  // 主件和附件 1
                f[j] = std::max(f[j], f[j - mw[i] - fw[i][1]] + mv[i] + fv[i][1]);
            if (j >= mw[i] + fw[i][2])  // 主件和附件 2
                f[j] = std::max(f[j], f[j - mw[i] - fw[i][2]] + mv[i] + fv[i][2]);
            if (j >= mw[i] + fw[i][1] + fw[i][2])
                f[j] = std::max(f[j], f[j - mw[i] - fw[i][1] - fw[i][2]] + mv[i] + fv[i][1] + fv[i][2]);
        }
    }

    std::cout << f[n] << "\n";
    return 0;
}
