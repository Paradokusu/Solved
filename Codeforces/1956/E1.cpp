#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), r;
	
	for (auto &i : a)
		std::cin >> i;
	
	if (n == 2) {
		while (a[0] && a[1]) {
			a[1] = std::max(0, a[1] - a[0]);
			a[0] = std::max(0, a[0] - a[1]);
		}
		
		if (a[1])
			std::cout << "1\n2\n";
		else if (a[0])
			std::cout << "1\n1\n";
		else
			std::cout << "0\n\n";
		return;
	}
	
	while ([&](){
		for (size_t i = 0; i < a.size(); i++)
			if (a[i] && a[(i + 1) % a.size()] && a[(i + 2) % a.size()])
				return 1;
		
		return 0;
	}())
		for (int i = 0; i < n; i++)
			a[(i + 1) % n] = std::max(0, a[(i + 1) % n] - a[i]);
	
	for (int i = 0; i < n; i++)
		if (a[i] && !a[(i + n - 1) % n])
			r.push_back(i);
	
	std::cout << r.size() << "\n";
	
	for (auto i : r)
		std::cout << i + 1 << " ";
	
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
