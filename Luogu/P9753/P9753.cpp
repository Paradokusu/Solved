#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e6 + 5;
constexpr int Alp = 29;

int n;
i64 ans, _Hash[N];
char s[N];

stack<i64> St, Pos;
unordered_set<i64> Set;
unordered_map<i64, i64> Map;

int main() {
	scanf("%d", &n);
	scanf(" %s", s + 1);

	/* Init */
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
	printf("%lld\n", ans);
	return 0;
}
