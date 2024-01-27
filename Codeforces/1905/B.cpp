#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> d(n + 1);

	for (int i = 1, a, b; i < n; i++) {
		std::cin >> a >> b;
		d[a]++, d[b]++;
	}

	int cot = 0;

	for (int i = 1; i <= n; i++) {
		cot += (d[i] == 1);
		d[i] = 0;
	}

	std::cout << (cot + 1) / 2 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
