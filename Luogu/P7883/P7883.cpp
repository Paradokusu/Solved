#include <bits/stdc++.h>

constexpr int N = 4e5 + 7;

int n;
long double w, ans, dis;
long double x, y, xx, yy;

struct node {
	long double a[5];
	
	bool operator < (const node &t) const {
		return a[0] * a[1] < t.a[0] * t.a[1];
	}
} p[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::mt19937_64 rand(time(nullptr));
	
	std::cin >> n;
	int k = std::min(n, 60);
	
	dis = rand();
	w = rand();
	
	for (int i = 1; i <= n; i++) {
		std::cin >> x >> y;
		p[i] = {x * w - y * dis, x * dis + y * w, x, y};
	}
	
	std::stable_sort(p + 1, p + n + 1);
	ans = 2e30 + 0.01;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k && i + j <= n; j++) {
			x = p[i].a[2];
			y = p[i].a[3];
			
			xx = p[i + j].a[2];
			yy = p[i + j].a[3];
			
			dis = (x - xx) * (x - xx) + (y - yy) * (y - yy);
			ans = std::min(ans, dis);
		}
	}
	
	std::cout << std::fixed << std::setprecision(0) << ans << "\n";
	return 0;
}
