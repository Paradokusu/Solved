#include <bits/stdc++.h>

constexpr int N = 55;
constexpr int inf = 2147483647;

int n, m;
int c[N];

bool judge(int t) {
	int cot = 0, res = t;
	
	for (int i = 1; i <= n; i++) {
		if (c[i] >= t)
			continue;
		
		/* 两个限制条件，用的 joker 张数超过了给的或者一个组合里用了超过一张 joker */
		
		cot += (t - c[i]);
		res -= (t - c[i]);
		
		if (cot > m || res < 0)
			return 0;
	}
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> c[i];
	
	int l = 1, r = inf;
	
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		
		if (judge(mid))
			l = mid;
		else
			r = mid - 1;
	}
	
	std::cout << l << "\n";
	return 0;
}
