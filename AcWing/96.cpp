#include <bits/stdc++.h>

void solve() {
	constexpr int N = 20;

	// std::array<int, N> d, f;
	int d[N], f[N];
	d[1] = 1;
	for (int i = 2; i <= 12; i++)
		d[i] = 2 * d[i - 1] + 1;
	// f.fill(0x3f);
	memset(f, 0x3f, sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= 12; i++)
		for (int j = 1; j < i; j++)
			f[i] = std::min(f[i], 2 * f[j] + d[i - j]);
	for (int i = 1; i <= 12; i++)
		std::cout << f[i] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
