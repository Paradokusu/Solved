#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 5;

int n, m, res, ans;
map<int, i64> lis[N];

int Srh(int x, int v) {
	int res = 0;
	auto p = lis[x].lower_bound(v);
	res = (p == lis[x].begin()) ? 0 : ((--p) -> second);
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		res = Srh(x, z); ++res;
		if (res > Srh(y, z)) {
			auto p = lis[y].lower_bound(z); lis[y][z] = res;
			for (auto q = p; q != lis[y].end(); ) {
				if ((q -> second) > res) break;
				q = lis[y].erase(q);
			}
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}
