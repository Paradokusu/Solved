#include <bits/stdc++.h>

struct node {
	int x, y;

	friend bool operator < (const node &a, const node &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	bool flg = 1;
	for (int i = 1; i <= n; i++)
		flg &= (a[i] == i);
	if (flg) {
		std::cout << n - 2 << "\n";
		return;
	}

	int ans = 0;
	std::map<node, int> f;
	std::vector<int> b(n + 1);

	for (int i = 1; i <= n; i++)
		b[i] = 0;

	std::priority_queue<int, std::vector<int>, std::greater<int>> q1;
	for (int i = 1; i <= n; i++) {
		q1.push(a[i]);
		while (q1.top() <= i) {
			q1.pop();
			if (q1.empty())
				break;
		}
		if (q1.size() == 1)
			b[i] = q1.top();
		if (q1.size() > 1)
			b[i] = -1;
	}

	std::priority_queue<int> q0;
	for (int i = n; i >= 1; i--) {
		q0.push(a[i]);
		while (q0.top() >= i) {
			q0.pop();
			if (q0.empty())
				break;
		}

		if (q0.size() == 1) {
			if (b[i]) {
				if (a[i] != i) continue;
				int u = b[i], v = q0.top();
				if (u > v) std::swap(u, v);
				f[{u, v}]++;
				ans = std::max(ans, f[{u, v}]);
			} else {
				int u = i, v = q0.top();
				if (u > v) std::swap(u, v);
				f[{u, v}]++;
				ans = std::max(ans, f[{u, v}]);
			}
		}

		if (q0.size() == 0) {
			if (b[i]) {
				int u = i, v = b[i];
				if (u > v) std::swap(u, v);
				f[{u, v}]++;
				ans = std::max(ans, f[{u, v}]);
			} else {
				b[i] = -2;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (b[i] == -2)
			ans++;
	}

	std::cout << ans << "\n";
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
