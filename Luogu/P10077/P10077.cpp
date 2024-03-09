#include <bits/stdc++.h>

constexpr int N = 5e5 + 1;
constexpr int inf = 2147483647;

int d, n;
int g, cot, ans;	// 当前取了 g 个数，每次读 cot 章
int a[N], tr[N * 2];

void Build(int o, int l, int r) {
	if (l == r) {
		tr[o] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	Build(o * 2, l, mid);
	Build(o * 2 + 1, mid + 1, r);
	
	tr[o] = std::min(tr[o * 2], tr[o * 2 + 1]);
}

void Query(int o, int l, int r) {
	if (l == r) {
		tr[o] = inf;
		g++;
		return;
	}
	
	int mid = (l + r) / 2;
	
	if (tr[o * 2] <= g) {
		Query(o * 2, l, mid);
	}
	
	if (tr[o * 2 + 1] <= g) {
		Query(o * 2 + 1, mid + 1, r);
	}
	
	tr[o] = std::min(tr[o * 2], tr[o * 2 + 1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> d >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	Build(1, 1, n);
	
	while (true) {
		ans++, cot++;
		Query(1, 1, n);
		
		if (tr[1] == inf) {
			break;
		}
		
		if (cot >= N) {
			std::cout << "-1\n";
			return 0;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}
