#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, rt;
int ans, num;
int ind[N], dp[N << 1];

int tot, head[N];
struct edge {
	int nxt, to;
} e[N << 1];

void addedge(int x, int y) {
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}

int dfs(int x, int y, int z) {
	if (ind[x] == 1) {
		ans += z, num++;
		dp[x] = -1;
		return 1;
	}
	
	dp[x] = 0;
	int cot = 0;
	for (int i = head[x]; i; i = e[i].nxt) {
		if (e[i].to ^ y) {
			cot |= dfs(e[i].to, x, z ^ 1);
			dp[x] += dp[e[i].to] + 1;
		}
	}
	
	if (cot) ++dp[x];
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
		ind[x]++, ind[y]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (ind[i] > 1)
			rt = i;
	}
	
	dfs(rt, rt, 1);
	printf("%d %d\n", (ans % num ? 3 : 1), dp[rt]);
	return 0;
}
