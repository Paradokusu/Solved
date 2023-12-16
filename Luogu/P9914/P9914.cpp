#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e6 + 5;

int n, m;
int a[N], b[N];
unordered_map<i64, int> Map;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0) { i64 t = 1ll * i * a[i]; Map[t]++; }
	}

	i64 ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		if (b[i] != 0) {
			i64 t = 1ll * i * b[i];
			if (Map.count(t)) { ans += Map[t]; }
		}
	}
	printf("%lld\n", ans);
	return 0;
}
