#include <bits/stdc++.h>

constexpr int N = 3e6 + 7;

int n, mr;
std::vector<int> lnk[N];
int f[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;
		lnk[y].push_back(x - 1);
		mr = std::max(mr, y);
	}
	
	for (int i = 1; i <= mr; i++) {
		f[i] = f[i - 1];
		
		for (size_t j = 0; j < lnk[i].size(); j++) {
			int stp = lnk[i][j];
			f[i] = std::max(f[i], f[stp] + i - stp);
		}
	}
	
	std::cout << f[mr] << "\n";
	return 0;
}
