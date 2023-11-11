#include <bits/stdc++.h>

void work(int n, std::vector<int> &a) {
	if (n == 1) {
		a[0] = 0;
		return;
	}
	if (n == (int) std::sqrt(n) * (int) std::sqrt(n)) {
		a[0] = 0;
		for (int i = 1; i < n; i++)
			a[i] = n - i;
		return;
	}
	if (n == (int) std::sqrt(n) * (int) std::sqrt(n) + 1) {
		for (int i = 0; i < n; i++)
			a[i] = n - i - 1;
		return;
	}

	int begin = ((int) std::sqrt(n) + 1) * ((int) std::sqrt(n) + 1) - n + 1;
	for (int i = begin; i < n; i++)
		a[i] = n - 1 - (i - begin);
	work(begin, a);
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 5);
	work(n, a);
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
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
