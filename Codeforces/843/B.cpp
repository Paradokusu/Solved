#include <bits/stdc++.h>

using namespace std;

constexpr int N = 50000 + 7;
constexpr int inf = numeric_limits<int>::max();

int n, x, start;
int a[N];

random_device rdv;
mt19937_64 myrand(rdv());

int main() {
	scanf("%d %d %d", &n, &start, &x);
	if (n < 2000) {
		int ans = inf;
		for (int i = 1; i <= n; i++) {
			printf("? %d\n", i);
			fflush(stdout);
			int val, nxt;
			scanf("%d %d", &val, &nxt);
			if (val >= x)
				ans = std::min(ans, val);
		}
		if (ans == inf) ans = -1;
		printf("! %d\n", ans);
		fflush(stdout);
	} else {
		int p = start, ans = 0;
		for (int i = 1; i <= n; i++)
			a[i] = i;
		shuffle(a + 1, a + n + 1, myrand);
		for (int i = 1; i <= 1000; i++) {
			printf("? %d\n", a[i]);
			fflush(stdout);
			int val, nxt;
			scanf("%d %d", &val, &nxt);
			if (val < x && val > ans) {
				p = a[i];
				ans = val;
			}
		}
		while (p != -1 && ans < x) {
			printf("? %d\n", p);
			fflush(stdout);
			int val, nxt;
			scanf("%d %d", &val, &nxt);
			ans = val;
			p = nxt;
		}
		if (ans < x) ans = -1;
		printf("! %d\n", ans);
		fflush(stdout);
	}
	return 0;
}
