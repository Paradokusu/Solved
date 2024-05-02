#include <bits/stdc++.h>

void solve() {
	int l, n, m;
	std::cin >> l >> n >> m;
	
	std::vector<int> a((n + 1) << 1), d((n + 1) << 1);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	
	d[n + 1] = l - a[n];
	
	int lt = 1, rt = l;
	
	while (lt < rt) {
		int sum = 0;
		
		for (int i = 1; i <= n + 1; i++)
			a[i] = d[i];
		
		int mid = (lt + rt + 1) >> 1;
		
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] < mid) {
				sum++;
				a[i + 1] = a[i + 1] + a[i];
			}
		}
		
		if (sum <= m)
			lt = mid;
		else
			rt = mid - 1;
	}
	
	std::cout << lt << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
