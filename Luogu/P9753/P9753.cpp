#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 2e6 + 5;
constexpr int Alp = 29;		// Hash 自然溢出

int n;
i64 ans;
std::string s;
std::array<i64, N> _Hash;
std::stack<i64> St, Pos;
std::unordered_set<i64> Set;
std::unordered_map<i64, i64> Map;

int main() {
	// freopen("game.in", "r", stdin);
	// freopen("game.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> s;

	/* Init */
	s = '#' + s;
	Set.insert(0);
	Map[0]++;

	/* Solve */
	for (int i = 1; i <= n; i++) {
		if (!St.empty() && St.top() == s[i] - 'a') {
			Map[_Hash[Pos.top() - 1]]++, _Hash[i] = _Hash[Pos.top() - 1];
			St.pop(), Pos.pop();
		} else {
			St.push(s[i] - 'a'), Pos.push(i);
			_Hash[i] = _Hash[i - 1] * Alp + s[i] - 'a' + 1;
			Set.insert(_Hash[i]);
			Map[_Hash[i]]++;
		}
	}

	for (auto i : Set)
		ans += Map[i] * (Map[i] - 1) / 2;

	/* Output */
	std::cout << ans << "\n";
	return 0;
}
