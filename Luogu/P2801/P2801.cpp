#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;

int n, m;
int block, num;
int a[N], L[N], R[N], bel[N], sum[N], add[N];

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
		bel[i] = (i - 1) / block + 1;
		sum[i] = a[i];
	}
	
	for (int i = 1; i <= num; i++) {
		std::sort(sum + L[i], sum + R[i] + 1);
	}
}

void ReSort(int x) {	
	for (int i = L[x]; i <= R[x]; i++) {
		sum[i] = a[i];
	}
	
	std::sort(sum + L[x], sum + R[x] + 1);
}

void Update(int l, int r, int x) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++)
			a[i] += x;
		
		ReSort(bel[l]);
		return;
	}
	
	for (int i = l; i <= R[bel[l]]; i++)
		a[i] += x;
	
	ReSort(bel[l]);
	
	for (int i = L[bel[r]]; i <= r; i++)
		a[i] += x;
	
	ReSort(bel[r]);
	
	for (int i = bel[l] + 1; i <= bel[r] - 1; i++)
		add[i] += x;
}

int BinSrh(int l, int r, int x) {
	int y = r;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		
		if (sum[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return y - l + 1;
}

int Query(int l, int r, int x) {
	int ans = 0;
	
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++)
			if (a[i] + add[bel[i]] >= x)
				ans++;
		
		return ans;
	}
	
	for (int i = l; i <= R[bel[l]]; i++) {
		if (a[i] + add[bel[i]] >= x)
			ans++;
	}
	
	for (int i = L[bel[r]]; i <= r; i++) {
		if (a[i] + add[bel[i]] >= x)
			ans++;
	}
	
	for (int i = bel[l] + 1; i <= bel[r] - 1; i++) {
		ans += BinSrh(L[i], R[i], x - add[i]);
	}
	
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
		
	Build();
	
	while (m--) {
		char opt;
		int l, r, c;
		std::cin >> opt >> l >> r >> c;
		
		if (opt == 'M') {
			Update(l, r, c);
		} else {
			std::cout << Query(l, r, c) << "\n";
		}
	}
	
	return 0;
}
