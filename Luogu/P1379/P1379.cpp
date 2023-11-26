#include <bits/stdc++.h>

constexpr int N = 15;

int bg, ed = 123804765;
std::array<int, N> a;
std::unordered_map<int, int> rec[2];	// 1 表示从最初状态开始的搜索
std::queue<std::pair<int, bool>> Q;		// 0 表示从初始状态开始的搜索

int change(int x, int op) {
	for (int i = 9; i; i--) a[i] = x % 10, x /= 10;	// 解开状态
	int p;
	for (int i = 1; i <= 9; i++)	// 找到 0 所在的格子
		if (a[i] == 0) {
			p = i;
			break;
		}
	if (op == 1) {
		if (p <= 3) return -1;	// 不能将 0 向上交换
		std::swap(a[p], a[p - 3]);
	} else if (op == 2) {
		if (p >= 7) return -1;	// 不能将 0 向下交换
		std::swap(a[p], a[p + 3]);
	} else if (op == 3) {
		if ((p % 3) == 1) return -1;	// 不能将 0 向左交换
		std::swap(a[p], a[p - 1]);
	} else if (op == 4) {
		if ((p % 3) == 0) return -1;	// 不能将 0 向右交换
		std::swap(a[p], a[p + 1]);
	}
	x = 0;
	for (int i = 1; i <= 9; i++) x = x * 10 + a[i];	// 计算状态
	return x;
}

void check(int x, std::pair<int, bool> h) {
	if (x != -1) {
		if (rec[h.second ^ 1].count(x) == true) {
			std::cout << rec[h.second ^ 1][x] + rec[h.second][h.first] + 1 << "\n";
			exit(0);
		} else {
			rec[h.second][x] = rec[h.second][h.first] + 1;
			Q.push({x, h.second});
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> bg;
	if (bg == ed) {
		std::cout << "0\n";
		return 0;
	}
	Q.push({bg, 0}), Q.push({ed, 1});
	while (!Q.empty()) {
		std::pair<int, bool> h = Q.front();
		Q.pop();
		int x = change(h.first, 1);	// 将 0 一个向上变换的转移
		check(x, h);
		x = change(h.first, 2);	// 下
		check(x, h);
		x = change(h.first, 3);	// 左
		check(x, h);
		x = change(h.first, 4);	// 右
		check(x, h);
	}
	return 0;
}
