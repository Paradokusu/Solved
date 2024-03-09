#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;
constexpr int M = std::sqrt(N) + 7;

int n, m;
int block, num, L, R, x, ans;
int c[M][N];

std::deque<int> a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	block = std::sqrt(n);
	num = (n - 1) / block + 1;
	
	for (int i = 0, inp; i < n; i++) {
		std::cin >> inp;
		a[i / block].push_back(inp);
		c[i / block][inp]++;
	}
	
	std::cin >> m;
	
	while (m--) {
		int opt, l, r, k;
		std::cin >> opt >> L >> R;
		
		L = (L + ans - 1) % n + 1;
		R = (R + ans - 1) % n + 1;
		
		if (L > R) {
			std::swap(L, R);
		}
		
		L--;
		l = L / block;
		r = R / block;
		
		if (opt == 2) {
			std::cin >> k;
			k = (k + ans - 1) % n + 1;
			ans = 0;
			
			if (l == r) {
				for (int i = L % block; i < R % block; i++)
					ans += (a[l][i] == k);
			} else {
				for (int i = l + 1; i < r; i++)
					ans += c[i][k];
				
				for (int i = L % block; i < a[i].size(); i++)
					ans += (a[l][i] == k);
				
				for (int i = 0; i < R % block; i++)
					ans += (a[r][i] == k);
			}
			
			std::cout << ans << "\n";
		} else {
			if (l == r) {
				R = R % block - 1;
				x = a[r][R];
				a[r].erase(a[r].begin() + R);
				a[l].insert(a[l].begin() + L % block, x);
			} else {
				for (int i = l; i < r;) {
					x = a[i].back();
					a[i].pop_back();
					c[i][x]--;
					i++;
					
					a[i].push_front(x);
					c[i][x]++;
				}
				
				R %= block;
				x = a[r][R];
				
				a[r].erase(a[r].begin() + R);
				c[r][x]--;
				
				a[l].insert(a[l].begin() + L % block, x);
				c[l][x]++;
			}
		}
	}
	
	return 0;
}
