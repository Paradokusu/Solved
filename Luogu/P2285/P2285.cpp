#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 7;

int n, m, ans;
int f[N];

struct pos {
	int x, y, t;
} q[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &q[i].t, &q[i].x, &q[i].y);

		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (f[j] + 1 > f[i] && abs(q[i].x - q[j].x) + abs(q[i].y - q[j].y) <= q[i].t - q[j].t)
				f[i] = f[j] + 1;
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}
