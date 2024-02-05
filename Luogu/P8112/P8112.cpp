#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e7 + 7;

int n, m;
int nxt[N], dp[N];
char s[N], t[N];

void kmp(char *str, int n) {
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && str[i] != str[j + 1])
			j = nxt[j];
		if (str[i] == str[j + 1])
			j++;
		nxt[i] = j;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf(" %s", t + 1);
	scanf(" %s", s + 1);
	
	kmp(t, n);
	t[n + 1] = '#';
	nxt[n + 1] = 1;
	
	memset(dp, 0x3f, sizeof(dp));

	const int inf = dp[0];
	dp[0] = 0;
	
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != t[j + 1])
			j = nxt[j];
		if (s[i] == t[j + 1])
			j++;

		dp[i] = min(dp[i], dp[i - j] + 1);
	}
	
	if (dp[m] < inf)
		printf("%d\n", dp[m]);
	else
		printf("Fake\n");
	
	return 0;
}
