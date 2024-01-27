#include <bits/stdc++.h>

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;

	int ans = 0;
	std::unordered_set<char> st;
	
	for (auto i : s) {
		st.insert(i);
		ans += st.size();
	}

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
