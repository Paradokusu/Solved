#include <bits/stdc++.h>

constexpr int N = 1007;
constexpr double eps = 1e-6;

int n, d, tot;

struct node {
	int x, y;
	double l, r;
} p[N];

bool cmp(const node &x, const node &y) {
	return x.l < y.l;
}

void solve() {
	for (int i = 1; i <= n; i++)
		std::cin >> p[i].x >> p[i].y;
	
	bool flg = 1;
	for (int i = 1; i <= n; i++) {
		if (p[i].y > d) {
			flg = 0;
			break;
		}
	}
	
	if (!flg) {
		std::cout << "Case " << ++tot << ": -1\n";
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		double k = std::sqrt(1.0 * d * d - 1.0 * p[i].y * p[i].y);
		p[i].l = p[i].x - k;
		p[i].r = p[i].x + k;
	}
	
	std::sort(p + 1, p + n + 1, cmp);
	
	int ans = 1;
	double pos = std::numeric_limits<double>::max();
	for (int i = 1; i <= n; i++) {
		if (pos + eps < p[i].l) {
			ans++;
			pos = p[i].r;
		} else
			pos = std::min(p[i].r, pos);
	}
	
	std::cout << "Case " << ++tot << ": " << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	while (std::cin >> n >> d && n && d)
		solve();
	
	return 0;
}
