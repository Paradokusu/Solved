#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;
constexpr int V = 50;

struct node {
	double x, y;

	friend bool operator < (const node &a, const node &b) {
		return a.x < b.x;
	}
} a[N];

int n;
double ans = (double) 1e18;

double Distance(node a, node b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;

	for (int i = 1; i <= n; i++)
		std::cin >> a[i].x >> a[i].y;

	std::sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n && j < i + V; j++)
			ans = std::min(ans, Distance(a[i], a[j]));

	std::cout << std::fixed << std::setprecision(4) << ans << "\n";
	return 0;
}
