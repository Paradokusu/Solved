#include <bits/stdc++.h>

int n;

std::string s;
std::set<std::pair<int, int>> a;

void solve(int t) {
	int x = 0, y = 0;
	std::set<std::pair<int, int>> p, np;
	
	for (int i = 1; i <= n; i++) {
		p.insert({x, y});
		
		int fx = x, fy = y;
		
		if (s[i] == 'L')
			fx--;
		else if (s[i] == 'R')
			fx++;
		else if (s[i] == 'U')
			fy++;
		else if (s[i] == 'D')
			fy--;
		
		if (t & (1 << (i - 1))) {
			if (p.count({fx, fy}))
				return;
			
			np.insert({fx, fy});
		} else {
			if (np.count({fx, fy}))
				return;
			
			x = fx, y = fy;
		}
	}
	
	a.insert({x, y});
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	std::cin >> s;
	s = '$' + s;
	
	for (int i = 0; i < (1 << n); i++)
		solve(i);
	
	std::cout << a.size() << "\n";
	
	for (auto i : a)
		std::cout << i.first << " " << i.second << "\n";
	
	return 0;
}
