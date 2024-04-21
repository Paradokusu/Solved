#include <bits/stdc++.h>

constexpr int N = 107;

int n, m, q;
std::string s, a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> q;
	std::cin >> s;
	s = '#' + s;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = '#' + a[i];
	}
	
	for (int p = 1; p <= q; p++) {
		if (s[p] == 'D') {
			for (int i = 1; i <= m; i++) {
				std::string t = "";
				
				for (int j = 1; j <= n; j++)
					if (a[j][i] != '.')
						t += a[j][i];
				
				for (int j = 1; j <= n - t.size(); j++) {
					a[j][i] = '.';
				}
				
				// std::cout << t.size() << "\n";
				int ln = n - t.size() + 1;
				
				for (int j = ln; j <= n; j++) {
					a[j][i] = t[0];
					t.erase(0, 1);
				}
				
				// std::cout << t << "\n";
			}
		}
		
		if (s[p] == 'U') {
			for (int i = 1; i <= m; i++) {
				std::string t = "";
				
				for (int j = 1; j <= n; j++)
					if (a[j][i] != '.')
						t += a[j][i];
				
				// std::cout << t.size() << "\n";
				int ln = t.size();
				
				for (int j = 1; j <= ln; j++) {
					a[j][i] = t[0];
					t.erase(0, 1);
				}
				
				// std::cout << t << "\n";
				
				for (int j = ln + 1; j <= n; j++)
					a[j][i] = '.';
			}
		}
		
		if (s[p] == 'L') {
			for (int i = 1; i <= n; i++) {
				std::string t = "";
				
				for (int j = 1; j <= m; j++) {
					if (a[i][j] != '.')
						t += a[i][j];
				}
				
				int ln = t.size();
				
				for (int j = 1; j <= ln; j++) {
					a[i][j] = t[0];
					t.erase(0, 1);
				}
				
				for (int j = ln + 1; j <= m; j++)
					a[i][j] = '.';
			}
		}
		
		if (s[p] == 'R') {
			for (int i = 1; i <= n; i++) {
				std::string t = "";
				
				for (int j = 1; j <= m; j++) {
					if (a[i][j] != '.')
						t += a[i][j];
				}
				
				int ln = t.size();
				
				for (int j = 1; j <= m - ln; j++)
					a[i][j] = '.';
				
				for (int j = m - ln + 1; j <= m; j++) {
					a[i][j] = t[0];
					t.erase(0, 1);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			std::cout << a[i][j];
		std::cout << "\n";
	}
	
	return 0;
}
