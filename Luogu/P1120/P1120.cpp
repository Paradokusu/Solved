#include <bits/stdc++.h>

int n, Max = -1e9, Min = 1e9;
std::vector<int> a, t(55);

void dfs(int res, int dep, int len, int p) {
	if (!res) { std::cout << len << "\n"; exit(0); }
	if (dep == len) { dfs(res - 1, 0, len, Max); return; }
	for (int i = p; i >= Min; i--) {
		if (t[i] && i + dep <= len) {
			t[i]--;
			dfs(res, i + dep, len, i);
			t[i]++;
			if (!dep || dep + i == len) break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	a.resize(n + 5);

	int sum = 0;
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		if (in <= 50) {
			a[i] = in;
			Max = std::max(Max, in), Min = std::min(Min, in);
			t[in]++, sum += in;
		}
	}
	
	int x = sum / 2;
	for (int i = Max; i <= x; i++)
		if (sum % i == 0) dfs(sum / i, 0, i, Max);
	std::cout << sum << "\n";
	return 0;
}
