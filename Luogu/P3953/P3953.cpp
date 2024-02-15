#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;

int t, n, m, k, p;
int d[N], f[N][55];
bool wrk[N][55];

struct edge {
	int to, val;
};

vector<edge> g[N], h[N];

int dp(int root, int l) {
	int ans = 0;

	if (l < 0 || l > k) return 0;
	if (wrk[root][l]) {
		wrk[root][l] = 0;
		return -1;
	}
	if (f[root][l] != -1) return f[root][l];

	wrk[root][l] = 1;
	for (size_t i = 0; i < h[root].size(); i++) {
		edge e = h[root][i];
		int v = e.to, w = e.val;
		int val = dp(v, d[root] + l - d[v] - w);

		if (val == -1) {
			wrk[root][l] = 0;
			return -1;
		}

		ans = (ans + val) % p;
	}

	wrk[root][l] = 0;
	if (root == 1 && l == 0) ans++;

	f[root][l] = ans;
	return ans;
}

int work() {
	scanf("%d %d %d %d", &n, &m, &k, &p);

	for (int i = 1; i <= n; i++) {
		g[i].clear();
		h[i].clear();
	}

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.to = b, e.val = c;
		g[a].push_back(e);
		e.to = a;
		h[b].push_back(e);
	}

	memset(d, 0x3f, sizeof(d));
	memset(f, -1, sizeof(f));

	queue<int> q;
	q.push(1);
	d[1] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (size_t i = 0; i < g[x].size(); i++) {
			int v = g[x][i].to, w = g[x][i].val;
			if (d[v] > d[x] + w) {
				d[v] = d[x] + w;
				q.push(v);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= k; i++) {
		int val = dp(n, i);
		if (val == -1) return -1;
		ans = (ans + val) % p;
	}

	return ans;
}

int main() {
	scanf("%d", &t);
	
	while (t--) {
		printf("%d\n", work());
	}

	return 0;
}
