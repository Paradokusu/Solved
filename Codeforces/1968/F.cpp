#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int T;
int n, q, a[N];
map<int, vector<int>> id;

void solve() {
	scanf("%d %d", &n, &q);
	id.clear();
	
	id[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		id[a[i]].push_back(i);
	}
	
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (a[r] == a[l - 1]) {
			printf("YES\n");
			continue;
		}
		
		int ql = *--lower_bound(id[a[l - 1]].begin(), id[a[l - 1]].end(), r);
		int qr = *lower_bound(id[a[r]].begin(), id[a[r]].end(), l);
		printf("%s\n", (ql > qr ? "YES" : "NO"));
	}
	
	printf("\n");
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
