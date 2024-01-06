#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3e5 + 5;

int n, q;
int fa[N], siz[N], ans[N], weight[N];
vector<int> son[N];

void dfs(int u) {
	siz[u] = 1, ans[u] = u;
	for (auto v : son[u]) {
		dfs(v);
		siz[u] += siz[v];
		weight[u] = max(weight[u], siz[v]);
	}
	for (auto v : son[u]) {
		int p = ans[v];
		while (p != u) {
			if (max(weight[p], siz[u] - siz[p]) <= siz[u] / 2) {
				ans[u] = p;
				break;
			} else {
				p = fa[p];
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int v = 2; v <= n; v++) {
		scanf("%d", &fa[v]);
		son[fa[v]].push_back(v);
	}
	dfs(1);
	while (q--) {
		int u;
		scanf("%d", &u);
		printf("%d\n", ans[u]);
	}
	return 0;
}
