#include <bits/stdc++.h>

int n;
size_t ans;
std::string s, t;
std::queue<int> q;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	std::cin >> s;
	std::cin >> t;
	
	if (s == t) {
		std::cout << "0\n";
		return 0;
	}
	
	int l = n - 1, r = n - 1;
	
	while (r >= 0) {
		while (r && t[r - 1] == t[r])
			r--;
		
		while (l >= 0 && (l > r || s[l] != t[r]))
			l--;
		
		if (l < 0) {
			std::cout << "-1\n";
			return 0;
		}
		
		while (!q.empty() && q.front() - q.size() >= r)
			q.pop();
		
		if (l != r)
			q.push(l);
		
		ans = std::max(ans, q.size() + 1);
		r--;
	}
	
	std::cout << ans << "\n";
	return 0;
}
