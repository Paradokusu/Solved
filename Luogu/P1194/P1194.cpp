#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3e5 + 5;

int a, b, cnt, ans, fa[N];

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

struct edge {
	int u, v, w;
} e[N];

bool cmp(const edge &x, const edge &y) {
	return x.w < y.w;
}

void Kruskal() {
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		ans += e[i].w;
		fa[v] = u;
		cnt++;
	}
}

int main() {
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= b; i++) {
		fa[i] = i;
		e[++cnt].v = i;
		e[cnt].w = a;
	}
	for (int i = 1, w; i <= b; i++) {
		for (int j = 1; j <= b; j++) {
			scanf("%d", &w);
			if (w) {
				e[++cnt].u = i;
				e[cnt].v = j, e[cnt].w = w;
			}
		}
	}
	Kruskal();
	printf("%d\n", ans);
	return 0;
}