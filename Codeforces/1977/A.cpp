#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n < m) {
		printf("No\n");
		return;
	}
	
	if (((n - m) % 2) == 0) printf("Yes\n");
	else printf("No\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

