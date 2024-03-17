#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n, m;
int block, num;	// 块的大小和块的个数
int a[N], L[N], R[N], bel[N];	// 原数组，区间和，懒标记，块左端点和块右端点，元素属于的块
i64 sum[N], add[N];

void Build() {
	block = std::sqrt(n);
	num = n / block;

	if (n % block)
		num++;
	
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	
	R[num] = n;	// 不完整的块
	
	for (int i = 1; i <= n; i++) {
		bel[i] = (i - 1) / block + 1;
	}
	
	for (int k = 1; k <= num; k++) {
		for (int i = L[k]; i <= R[k]; i++)
			sum[k] += a[i];
	}
}

void Reset(int x) {	// 重新统计当前块前缀和
	sum[x] = 0;
	
	for (int i = L[x]; i <= R[x]; i++)
		sum[x] += a[i];
}

void Update(int l, int r, int x) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++)
			a[i] += x;
		
		Reset(bel[l]);
		return;
	}
	
	// 处理散块

	for (int i = l; i <= R[bel[l]]; i++)
		a[i] += x;
	
	for (int i = L[bel[r]]; i <= r; i++)
		a[i] += x;
	
	Reset(bel[l]);
	Reset(bel[r]);
	
	// 处理整块
	
	for (int i = bel[l] + 1; i < bel[r]; i++) {
		add[i] += x;
	}
}

i64 Query(int l, int r) {
	i64 ans = 0;
	
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++)
			ans += a[i] + add[bel[i]];
		
		return ans;
	}
	
	for (int i = l; i <= R[bel[l]]; i++)
		ans += a[i] + add[bel[i]];
	
	for (int i = L[bel[r]]; i <= r; i++)
		ans += a[i] + add[bel[i]];
	
	for (int i = bel[l] + 1; i < bel[r]; i++)
		ans += sum[i] + add[i] * (R[i] - L[i] + 1);
	
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	Build();
	
	for (int i = 1; i <= m; i++) {
		int opt, l, r, x;
		std::cin >> opt >> l >> r;
		
		if (opt == 1) {
			std::cin >> x;
			Update(l, r, x);
		} else {
			std::cout << Query(l, r) << "\n";
		}
	}
	
	return 0;
}
