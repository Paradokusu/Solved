#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 7;
constexpr int M = 5e4 + 7;

int n, m, q;

struct edge {
	int u, v, w;
} e[M];

int ans[M], fa[M];
unordered_set<int> s[N];

bool cmp(const edge &a, const edge &b) {
	return a.w > b.w;
}

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void init() {
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

void Kruskal() {
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		else {
			if (s[fu].size() > s[fv].size())
				swap(fu, fv);
			vector<int> t;
			for (auto i : s[fu]) {
				int id = i;
				if (s[fv].count(id)) {
					ans[id] = w;
					t.emplace_back(id);
				}
				s[fv].insert(id);
			}
			for (size_t i = 0; i < t.size(); i++)
				s[fv].erase(t[i]);
			fa[fu] = fv;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	init();
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		s[u].insert(i), s[v].insert(i);
	}
	Kruskal();
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}
