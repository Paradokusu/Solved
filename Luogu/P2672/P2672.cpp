#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n;
int sum[N], q[N], h[N];

struct node {
	int s, a;
} v[N];

bool cmp(const node &x, const node &y) {
	return x.a > y.a;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i].s;
	}
	
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i].a;
	}
	
	std::sort(v + 1, v + n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i].a;
		q[i] = std::max(q[i - 1], 2 * v[i].s);
	}
	
	for (int i = n; i >= 1; i--) {
		h[i] = std::max(h[i + 1], 2 * v[i].s + v[i].a);
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << std::max(sum[i] + q[i], sum[i - 1] + h[i]) << "\n";
	}
	
	return 0;
}
