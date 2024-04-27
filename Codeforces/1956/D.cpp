#include <bits/stdc++.h>

constexpr int N = 30;

int n, sum, mxn;
int a[N];
bool v[N];

std::vector<std::pair<int, int>> res, g;

void d(int l, int r) {
	if (l == r) {
		if (a[l] != 0) {
			a[l] = 0;
			res.push_back({l, r});
		}
		
		return;
	}
	
	if (a[r] == r - l) {
		d(l, r - 1);
		return;
	}
	
	d(l, r - 1);
	
	res.push_back({l, r});
	
	for (int i = l; i <= r; i++)
		a[i] = r - l;
	
	d(l, r - 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	for (int S = 0; S < (1 << n); S++) {
		for (int i = 1; i <= n; i++)
			v[i] = (S >> (i - 1)) & 1;
		
		int l = 0, r = -1, s = 0;
		std::vector<std::pair<int, int>> pt;
		
		for (int i = 1; i <= n; i++) {
			if (v[i])
				if (v[i - 1])
					r = i;
				else
					l = r = i;
			else {
				s += (r - l + 1) * (r - l + 1);
				
				if (l != 0)
					pt.push_back({l, r});
				
				l = 0, r = -1;
				s += a[i];
			}
		}
		
		if (v[n] == 1 && l != 0) {
			pt.push_back({l, r});
			s += (r - l + 1) * (r - l + 1);
		}
		
		if (s > mxn) {
			mxn = s;
			g = pt;
		}
	}
	
	for (auto [l, r] : g) {
		d(l, r);
		res.push_back({l, r});
	}
	
	std::cout << mxn << " " << res.size() << "\n";
	
	for (auto [l, r] : res) {
		std::cout << l << " " << r << "\n";
	}
	
	return 0;
}
