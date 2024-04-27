#include <bits/stdc++.h>

constexpr int N = 2e6 + 7;

int n, cot;
int L[N], R[N], t[N];
int fa[N << 1], s[N], pre[N], suf[N];

void init() {
	for (int i = 1; i <= (n << 1) + 1; i++)
		fa[i] = i;
	
	for (int i = 0; i <= n + 1; i++)
		s[i] = t[i] = pre[i] = suf[i] = 0;
}

int find(int x) {
	while (x ^ fa[x])
		x = fa[x] = fa[fa[x]];

	return x;
}

void solve() {
	std::cin >> n;

	init();
	
	for (int i = 1; i <= n; i++) {
		std::cin >> L[i] >> R[i];
		s[std::max(1, i - R[i])]++;
		s[std::max(0, i - L[i]) + 1]--;
		t[std::min(n + 1, i + L[i])]++;
		t[std::min(n, i + R[i]) + 1]--;
	}
	
	cot = n;
	
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		t[i] += t[i - 1];
		
		if (s[i] && t[i])
			suf[i] = pre[i] = ++cot;
	}
	
	suf[n + 1] = 0;
	
	for (int i = 1; i <= n; i++)
		pre[i] = (pre[i] ? pre[i] : pre[i - 1]);
	
	for (int i = n; i >= 1; i--)
		suf[i] = (suf[i] ? suf[i] : suf[i + 1]);
	
	for (int i = 1; i <= n; i++) {
		int l = std::max(1, i - R[i]);
		int r = std::max(0, i - L[i]);
		
		if (l <= r) {
			l = suf[l], r = pre[r];
			
			if (l && r && l <= r)
				for (int i = find(l); i < r; i = find(i))
					fa[i] = i + 1;
		}
		
		l = std::min(n + 1, i + L[i]);
		r = std::min(n, i + R[i]);
		
		if (l <= r) {
			l = suf[l], r = pre[r];
			
			if (l && r && l <= r)
				for (int i = find(l); i < r; i = find(i))
					fa[i] = i + 1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int l = std::max(1, i - R[i]);
		int r = std::max(0, i - L[i]);
		
		if (l <= r) {
			l = suf[l], r = pre[r];
			
			if (l && r && l <= r)
				fa[find(i)] = find(l);			
		}
		
		l = std::min(n + 1, i + L[i]);
		r = std::min(n, i + R[i]);
		
		if (l <= r) {
			l = suf[l];
			r = pre[r];
			
			if (l && r && l <= r)
				fa[find(i)] = find(l);
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= cot; i++)
		if (fa[i] == i)
			ans++;
	
	std::cout << ans << "\n";
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
