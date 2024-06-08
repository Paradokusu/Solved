#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 3e5 + 7;

mt19937_64 myrand(time(nullptr));

int n, m;
i64 rnds1[N], rnds2[N];

void solve() {
	scanf("%d %d", &n, &m);
	vector<vector<bool>> table(n + 1, vector<bool>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch;
			scanf(" %c", &ch);
			table[i][j] = ch - '0';
		}
	}
	
	for (int i = 1; i <= n; i++) {
		rnds1[i] = myrand();
		rnds2[i] = myrand();
	}
	
	int res = 0;
	map<pair<i64, i64>, int> ans;
	pair<int, int> ind = {0, 0};
	
	for (int j = 1; j <= m; j++) {
		i64 sm1 = 0, sm2 = 0;
		for (int i = 1; i <= n; i++) {
			if (table[i][j]) {
				sm1 ^= rnds1[i];
				sm2 ^= rnds2[i];
			}
		}
		for (int i = 1; i <= n; i++) {
			sm1 ^= rnds1[i];
			sm2 ^= rnds2[i];
			ans[{sm1, sm2}]++;
			if (res < ans[{sm1, sm2}]) {
				res = ans[{sm1, sm2}];
				ind = {j, i};
			}
			sm1 ^= rnds1[i];
			sm2 ^= rnds2[i];
		}
	}
	
	printf("%d\n", res);
	string is(n, '0');
	for (int i = 1; i <= n; i++) {
		if (table[i][ind.first]) {
			if (i != ind.second)
				is[i - 1] = '1';
		} else if (ind.second == i) {
			is[i - 1] = '1';
		}
	}
	cout << is << "\n";
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
