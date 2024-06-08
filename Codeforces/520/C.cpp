#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

int n, mx;
int res, ans;
int cA, cC, cG, cT;
char c[N];

signed main() {
	scanf("%lld", &n);
	scanf(" %s", c + 1);
	
	for (int i = 1; i <= n; i++) {
		if (c[i] == 'A') cA++;
		if (c[i] == 'C') cC++;
		if (c[i] == 'G') cG++;
		if (c[i] == 'T') cT++;
	}
	
	mx = max({cA, cC, cG, cT});
	if (cA == mx) res++;
	if (cC == mx) res++;
	if (cG == mx) res++;
	if (cT == mx) res++;
	
	ans = 1;
	while (n--)
		ans = ans * res % MOD;
	
	printf("%lld\n", ans);
	return 0;
}

