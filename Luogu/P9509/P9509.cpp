#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;
constexpr int B = 2500007;

int T, n;
int a[N << 1], f[2][N << 1];

bitset<B> s, b, c;

void solve() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	a[n + 1] = 0;
	
	if (sum % n == 0) {
		int p = sum / n;
		s.reset(), b.reset();
		s.set(0), b.set(0);
		
		for (int i = 1; i <= n; i++) {
			a[i] -= p;
			if (!a[i]) {
				printf("Yes\n");
				return;
			}
			if (a[i] > 0) {
				// equals f[i][j] |= f[i - 1][i - a[i]]
				b |= b << a[i];
			} else {
				s |= s << (-a[i]);
			}
		}
		
		c = s & b;
		if (c.count() > 2) printf("Yes\n");
		else printf("No\n");
	} else
		printf("No\n");
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
