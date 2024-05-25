#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5007;

int T, n;
char s[N], t[N], ed[N];

void solve() {
	scanf("%d", &n);
	scanf(" %s", s);
	
	for (int k = n; k; k--) {
		memset(ed, 0, sizeof(ed));
		for (int i = 0; i < n; i++)
			t[i] = s[i] - '0';
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt -= ed[i];
			t[i] ^= (cnt & 1);
			if (!t[i]) {
				if (i + k <= n) {
					++ed[i + k], ++cnt;
					t[i] = 1;
				} else break;
			}
		}
		
		if (*min_element(t, t + n) == 1) {
			printf("%d\n", k);
			return;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
