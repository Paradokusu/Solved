#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, m;
int block, num;
int a[N], bid[N], L[N], R[N];
int to[N], d[N], cnt[N];

void Init() {
	std::cin >> n >> m;

	block = std::sqrt(n);
	num = (n - 1) / block + 1;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		bid[i] = (i - 1) / block + 1;
	}
	
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	
	R[num] = n;
	
	for (int i = n; i; i--) {
		if (i + a[i] > R[bid[i]]) {
			cnt[i] = 1;
			to[i] = i + a[i];
			d[i] = i;
		} else {
			cnt[i] = cnt[i + a[i]] + 1;
			to[i] = to[i + a[i]];
			d[i] = d[i + a[i]];
		}
	}
}

void Modify(int x, int k) {
	a[x] = k;
	int bel = (x - 1) / block + 1;
	
	for (int i = R[bel]; i >= L[bel]; i--) {
		if (i + a[i] > R[bel]) {
			cnt[i] = 1;
			to[i] = i + a[i];
			d[i] = i;
		} else {
			cnt[i] = cnt[i + a[i]] + 1;
			to[i] = to[i + a[i]];
			d[i] = d[i + a[i]];
		}
	}
}

std::pair<int, int> Query(int pos) {
	int res = 0, lst;
	
	while (pos <= n) {
		res += cnt[pos];
		lst = d[pos];
		pos = to[pos];
	}
	
	return {lst, res};
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	Init();
	
	while (m--) {
		int opt, x, k;
		std::cin >> opt;
		
		if (opt == 1) {
			std::cin >> x;
			std::pair<int, int> p = Query(x);
			std::cout<< p.first << " " << p.second << "\n";
		} else {
			std::cin >> x >> k;
			Modify(x, k);
		}
	}
	
	return 0;
}
