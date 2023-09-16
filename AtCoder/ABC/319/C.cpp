#include <bits/stdc++.h>

void solve() {
	std::array<int, 9> cells;
	for (auto &&i : cells)
		std::cin >> i;

	std::vector<std::tuple<int, int, int>> row {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};
	std::array<int, 9> order;
	std::iota(order.begin(), order.end(), 0);

	int sum = 0, all = 0;
	do {
		all++;
		bool flag = false;
		for (auto &&[a, b, c] : row) {
			if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
				flag = true;
			else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b])
				flag = true;
			else if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])
				flag = true;
		}

		if (!flag) ++sum;
	} while (std::ranges::next_permutation(order).found);

	std::cout << std::fixed << std::setprecision(10) << (double) sum / all << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
