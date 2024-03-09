#include <bits/stdc++.h>

constexpr int N = 5e5 + 7;

int n, m;
int block, num;
int a[N], b[N], L[N], R[N], bid[N];

void Build() {
	block = std::sqrt(n);
	num = (n - 1) / block + 1;
	
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	
	R[num] = n;
	
	for (int i = 1; i <= n; i++) {
		bid[i] = (i - 1) / block + 1;
	}
	
	for (int i = 1; i <= num; i++) {
		std::sort(b + L[i], b + R[i] + 1);
	}
}

void Update(int p, int x) {
	int val = a[p], id = bid[p];
	a[p] = x;
	
	for (int i = L[id]; i <= R[id]; i++) {
		if (b[i] == val) {
			b[i] = x;
			break;
		}
	}
	
	std::sort(b + L[id], b + R[id] + 1);
}

int Query(int l, int r, int c) {
	int res = 0;
	
	if (bid[l] == bid[r]) {
		for (int i = l; i <= r; i++)
			if (a[i] >= c)
				res++;
		
		return res;
	}
	
	for (int i = l; i <= R[bid[l]]; i++) {
		if (a[i] >= c)
			res++;
	}
	
	for (int i = L[bid[r]]; i <= r; i++) {
		if (a[i] >= c)
			res++;
	}
	
	for (int i = bid[l] + 1; i <= bid[r] - 1; i++)
		res += R[i] - (std::lower_bound(b + L[i], b + R[i] + 1, c) - b) + 1;
	
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	
	Build();
	
	std::cin >> m;
	
	while (m--) {
		int opt, a, b, c;
		std::cin >> opt >> a >> b;
		
		if (opt == 0) {
			std::cin >> c;
			std::cout << Query(a, b, c) << "\n";
		} else {
			Update(a, b);
		}
	}
	
	return 0;
}
