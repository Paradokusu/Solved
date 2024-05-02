#include <bits/stdc++.h>

constexpr int N = 5e4 + 7;
constexpr int M = N << 1;
constexpr int inf = 2147483647;

int n, m, rt;

int tot, head[M], nxt[M], to[M], W[M];
void addedge(int u, int v, int w) {
	to[tot] = v;
	W[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot++;
}

int res;
int dp[N], tag[N], q[N];	// dp[i]: 向上贡献的最长链长度

void dfs(int x, int lst, int lim) {
	for (int i = head[x]; ~i; i = nxt[i])
		if (to[i] != lst)
			dfs(to[i], x, lim);
	
	int	tail = 0;
	
	for (int i = head[x]; ~i; i = nxt[i])
		if (to[i] != lst)
			q[++tail] = dp[to[i]] + W[i];
	
	std::sort(q + 1, q + tail + 1);
	
	for (int i = tail; i >= 1 && q[i] >= lim; i--) {	// 把已经成为赛道的边直接去掉
		tail--;
		res--;
	}
	
	for (int i = 1; i <= tail; i++) {
		if (tag[i] != x) {
			int l = i + 1, r = tail, pst = tail + 1;	// 二分另一条链使得刚好能组成赛道
			
			while (l <= r) {
				int mid = (l + r) >> 1;
				
				if (q[i] + q[mid] >= lim) {
					pst = mid;
					r = mid - 1;
				} else
					l = mid + 1;
			}
			
			while (tag[pst] == x && pst <= tail)	// 如果二分到的是已经选择过的链那么继续往选取
				pst++;
			
			if (pst <= tail) {	// 特判溢出区
				tag[i] = tag[pst] = x;
				res--;
			}
		}
	}
	
	dp[x] = 0;
	
	for (int i = tail; i >= 1; i--) {
		// 找没有选过的最长链并且传递，计算贡献
		if (tag[i] != x) {
			dp[x] = q[i];
			break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::mt19937_64 rand(time(nullptr));
	memset(head, -1, sizeof(head));

	std::cin >> n >> m;
	
	for (int i = 1; i < n; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	
	rt = rand() % n + 1;
	
	int l = 0, r = inf, ans = 0;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		res = m;
		
		memset(tag, 0, sizeof(tag));
		
		dfs(rt, 0, mid);
		
		if (res <= 0) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	
	std::cout << ans << "\n";
	return 0;
}
