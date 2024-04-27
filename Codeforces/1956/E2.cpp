#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int a[N];
bool lv[N];

void solve() {
	int n;
	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	if (n == 2) {
		while (a[1] && a[2]) {
			a[2] = std::max(0, a[2] - a[1]);
			a[1] = std::max(0, a[1] - a[2]);
		}
		
		lv[1] = (a[1] > 0);
		lv[2] = (a[2] > 0);
	} else if (n == 3) {
		while (a[1] && a[2] && a[3]) {
			a[2] = std::max(0, a[2] - a[1]);
			a[3] = std::max(0, a[3] - a[2]);
			a[1] = std::max(0, a[1] - a[3]);
		}
		
		lv[1] = (!a[3] && a[1]);
		lv[2] = (!a[1] && a[2]);
		lv[3] = (!a[2] && a[3]);
	} else {
		std::function<bool()> check = [&]() {
			a[n + 1] = a[1];
			a[n + 2] = a[2];
			a[n + 3] = a[3];
			
			for (int i = 1; i <= n; i++)
				if (a[i] && a[i + 1] && a[i + 2] && a[i + 3])
					return 1;
			
			return 0;
		};
		
		while (check()) {
			for (int i = 1; i <= n; i++)
				a[i % n + 1] = std::max(0, a[i % n + 1] - a[i]);
		}
		
		for (int i = 1; i <= n; i++)	
			lv[i] = 0;
		
		auto atk = [&](i64 x, i64 y) {
			i64 k = x / y;
			return (2 * x - (k + 1) * y) * k / 2;
		};
		
		for (int p = 1; p <= n; p++) {
			if (a[p] && a[p % n + 1])
				a[p % n + 1] = std::max(0, a[p % n + 1] - a[p]);
			else
				break;
		}
		
		for (int i = 1; i <= n; i++) {
			if (!a[i] && a[i % n + 1]) {
				lv[i % n + 1] = 1;
				lv[(i + 2) % n + 1] = (a[(i + 2) % n + 1] > atk(a[(i + 1) % n + 1], a[i % n + 1]));
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i <= n; i++)
		if (lv[i])
			ans++;
	
	std::cout << ans << "\n";
	
	for (int i = 1; i <= n; i++)
		if (lv[i])
			std::cout << i << " ";
	
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
