#include <bits/stdc++.h>

constexpr int N = 2e5 * 2;

int t, n;
int a[N], b[N];
int tmin[N * 2], tmax[N * 2], las[N];

std::bitset<N> ans;

void PushUp(int o) {
	tmax[o] = std::max(tmax[o * 2], tmax[o * 2 + 1]);
	tmin[o] = std::min(tmin[o * 2], tmin[o * 2 + 1]);
}

void Build(int o, int l, int r) {
	if (l == r) {
		tmin[o] = b[l];
		tmax[o] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	Build(o * 2, l, mid);
	Build(o * 2 + 1, mid + 1, r);
	PushUp(o);
}

int QueryMax(int o, int l, int r, int x, int y) {
	if (x <= l && r <= y)
		return tmax[o];
	
	int mid = (l + r) / 2;
	int res = 0;
	
	if (mid >= x)
		res = std::max(res, QueryMax(o * 2, l, mid, x, y));
	
	if (mid < y)
		res = std::max(res, QueryMax(o * 2 + 1, mid + 1, r, x, y));
	
	return res;
}

int QueryMin(int o, int l, int r, int x, int y) {
	if (x <= l && r <= y)
		return tmin[o];
	
	int mid = (l + r) / 2;
	int res = n + 1;
	
	if (mid >= x)
		res = std::min(res, QueryMin(o * 2, l, mid, x, y));
	
	if (mid < y)
		res = std::min(res, QueryMin(o * 2 + 1, mid + 1, r, x, y));
	
	return res;
}

void solve() {
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	
	Build(1, 1, n);
	
	memset(las, 0, sizeof(las));
	ans.reset();
	
	for (int i = 1; i <= n; i++) {
		las[a[i]] = i;
		
		if (!las[b[i]])
			continue;
		
		if (QueryMin(1, 1, n, las[b[i]], i) < b[i] || QueryMax(1, 1, n, las[b[i]], i) > b[i])
			continue;
		
		ans[i] = 1;
	}
	
	memset(las, 0, sizeof(las));
	
	for (int i = n; i >= 1; i--) {
		las[a[i]] = i;
		
		if (!las[b[i]])
			continue;
		
		if (QueryMin(1, 1, n, i, las[b[i]]) < b[i] || QueryMax(1, 1, n, i, las[b[i]]) > b[i])
			continue;
		
		ans[i] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (ans[i])
			continue;
		
		std::cout << "NO\n";
		return;
	}
	
	std::cout << "YES\n";
	return;
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
