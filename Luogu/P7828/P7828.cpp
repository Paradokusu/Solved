#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int M = 1e6 + 7;

int n, k, m, siz;
int a[N], P[N], t[N], sz[N];
i64 ans, as[N], del[M];

std::vector<int> p[N];

struct node {
	bool f;
	int id, b;
};

std::vector<node> q[N];

int lowbit(int x) {
	return x & (-x);
}

int Wrk(int a, int b) {
	int l = 0, res = 0;
	
	if (!sz[a])
		return 0;
	
	for (auto i : p[b]) {
		while (l < sz[a] && p[a][l] < i)
			l++;
		
		res += l;
	}
	
	return res;
}

void Add(int x) {
	while (x <= k) {
		t[x]++;
		x += lowbit(x);
	}
}

int Query(int x) {
	int res = 0;
	
	while (x) {
		res += t[x];
		x -= lowbit(x);
	}
	
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> k >> m;
	
	siz = std::sqrt(n);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		p[a[i]].push_back(i);
	}
	
	for (int i = 1; i <= k; i++) {
		P[i] = i;
		sz[i] = p[i].size();
	}
	
	for (int i = 1; i <= n; i++) {
		ans += Query(k) - Query(a[i]);
		Add(a[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		int qs;
		std::cin >> qs;
		
		int &x = P[qs], &y = P[qs + 1];
		
		if (sz[x] <= siz && sz[y] <= siz) {
			del[i] = Wrk(x, y) * 2 - sz[x] * sz[y];
		} else if (sz[x] > sz[y]) {
			q[x].push_back({0, i, y});
		} else {
			q[y].push_back({1, i, x});
		}
		
		std::swap(x, y);
	}
	
	for (int i = 1; i <= k; i++) {
		if (!q[i].empty()) {
			int npos = 0;
			
			for (int j = 1; j <= k; j++)
				as[j] = 0;
			
			for (int j = 1; j <= n; j++) {
				if (a[j] == i)
					npos++;
				else
					as[a[j]] += npos;
			}
			
			for (auto d : q[i]) {
				del[d.id] = 1ll * sz[d.b] * sz[i] - as[d.b] * 2;
				
				if (!d.f)
					del[d.id] *= -1;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		ans += del[i];
		std::cout << ans << "\n";
	}
	
	return 0;
}