#include <bits/stdc++.h>

constexpr int N = 30;
constexpr int Inf = 0x3f3f3f;

int n, m, ans = Inf;
std::vector<int> mins, minv;

void dfs(int dep, int r, int h, int s, int v) {
	int high = h;
	if (dep == 0) {
		if (v == n) ans = std::min(ans, s);
		return;
	}
	if (s + mins[dep - 1] >= ans) return;	// 当前面积大于最优值
	if (v + minv[dep - 1] > n) return;	// 当前体积大于要求
	if (2 * (n - v) / r + s >= ans) return;	// 当前体积表面积已经大于最大值
	for (int i = r - 1; i >= dep; i--) {	// 枚半径
		if (dep == m) s = i * i;
		high = std::min(h - 1, (n - minv[dep - 1] - v) / i / i);
		for (int j = high; j >= dep; j--) dfs(dep - 1, i, j, s + 2 * i * j, v + i * i * j);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	mins.resize(n + 5), minv.resize(n + 5);
	for (int i = 1; i <= m; i++) {
		mins[i] = mins[i - 1] + 2 * i * i;
		minv[i] = minv[i] + i * i * i;
	}
	dfs(m, n, n, 0, 0);
	if (ans == Inf) std::cout << "0\n";
	else std::cout << ans << "\n";
	return 0;
}
