#include <bits/stdc++.h>

#define inline inline __attribute__((always_inline))

using namespace std;
constexpr int N = 1e6 + 5;

int n, x;
int t[N], s[N];

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	for (int i = n - 1; i >= 1; i--) {
		int k = t[i + 1] - t[i] + 1;
		for (int j = k; j <= x && s[j] == 0; j++)	// 提前处理好时间差
			s[j] = i;
	}
	for (int i = 1; i <= x; i++) {
		int ans = max(t[s[i]] + x, t[n] + i);		// 将任务交给 A 还是交给 B
		printf("%d\n", ans);
	}
	return 0;
}
