#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int n, m;
int block, num;
int a[N], bid[N], dis[N], to[N], L[N], R[N];

void Build() {
	block = std::sqrt(n);
	num = n / block;
	
	if (n % block)
		num++;

	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	
	R[num] = n;
	
	for (int i = 1; i <= n; i++) {
		bid[i] = (i - 1) / block + 1;
	}
	
	for (int i = n; i; i--) {
		if (bid[i + a[i]] != bid[i]) {
			dis[i] = 1;
			to[i] = i + a[i];
		} else {
			dis[i] = dis[i + a[i]] + 1;
			to[i] = to[i + a[i]];
		}
	}
}

void Update(int x, int c) {
	a[x] = c;
	
	for (int i = R[bid[x]]; i >= L[bid[x]]; i--) {
		if (bid[i + a[i]] != bid[i]) {
			dis[i] = 1;
			to[i] = i + a[i];
		} else {
			dis[i] = dis[i + a[i]] + 1;
			to[i] = to[i + a[i]];
		}
	}
}

int Query(int pos) {
	int ans = 0;
	
	while (pos <= n) {
		ans += dis[pos];
		pos = to[pos];
	}
	
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	Build();
	
	std::cin >> m;
	
	while (m--) {
		int opt, j;
		std::cin >> opt >> j;
		
		if (opt == 1) {
			std::cout << Query(j + 1) << "\n";
		} else {
			int k;
			std::cin >> k;
			Update(j + 1, k);
		}
	}
	
	return 0;
}
