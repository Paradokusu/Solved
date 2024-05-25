#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

struct rel {
	int x, a, b;
} r[N];

int n, m;
int num, num2, cot;
int top, h, tail;

int head[N], head2[N], lnk[N];
int dfn[N], low[N], stc[N];
int siz[N], que[N], deg[N];
int candy[N];

bool vis[N];

i64 ans;

struct edge {
	int to, nxt;
	bool eq;	// equal, 可否相等
} e[N << 1], e2[N << 1];

void add(int u, int v, bool p) {
	e[++num].to = v;
	e[num].eq = p;
	e[num].nxt = head[u];
	head[u] = num;
}

void add2(int u, int v, bool p) {
	deg[v]++;
	e2[++num2].to = v;
	e2[num2].eq = p;
	e2[num2].nxt = head2[u];
	head2[u] = num2;
}

void dfs(int x) {
	dfn[x] = low[x] = ++cot;
	stc[++top] = x;
	
	for (int i = head[x]; i; i = e[i].nxt) {
		if (!dfn[e[i].to]) {
			dfs(e[i].to);
			low[x] = std::min(low[x], low[e[i].to]);
		} else if (!lnk[e[i].to])
			low[x] = std::min(low[x], dfn[e[i].to]);
	}
	
	if (dfn[x] == low[x]) {
		lnk[0]++;
		
		while (top) {
			lnk[stc[top]] = lnk[0];
			siz[lnk[0]]++;
			
			if (stc[top--] == x)
				break;
		}
	}
}

void ReBuild() {
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nxt) {
			if (lnk[i] != lnk[e[j].to])
				add2(lnk[i], lnk[e[j].to], 1);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (r[i].x == 2) {
			if (lnk[r[i].a] == lnk[r[i].b]) {
				std::cout << "-1\n";
				exit(0);
			} else
				add2(lnk[r[i].a], lnk[r[i].b], 0);
		} else if (r[i].x == 4) {
			if (lnk[r[i].a] == lnk[r[i].b]) {
				std::cout << "-1\n";
				exit(0);
			} else
				add2(lnk[r[i].b], lnk[r[i].a], 0);
		}
	}
}

void Topo() {
	for (int i = 1; i <= lnk[0]; i++) {
		if (!deg[i]) {
			que[++tail] = i;
			vis[i] = 1;
			candy[i] = 1;	// 记录 i 节点每个孩子需要多少糖
		}
	}
	
	while (h < tail) {
		int x = que[++h];
		
		for (int i = head2[x]; i; i = e2[i].nxt) {
			if (!(--deg[e2[i].to])) {
				que[++tail] = e2[i].to;
				vis[e2[i].to] = 1;
			}
			
			if (!e2[i].eq)
				candy[e2[i].to] = std::max(candy[e2[i].to], candy[x] + 1);
			else
				candy[e2[i].to] = std::max(candy[e2[i].to], candy[x]);
		}
	}
	
	for (int i = 1; i <= lnk[0]; i++) {
		if (!vis[i]) {
			std::cout << "-1\n";
			exit(0);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		std::cin >> r[i].x >> r[i].a >> r[i].b;
		
		if (r[i].x == 1) {
			add(r[i].a, r[i].b, 1);
			add(r[i].b, r[i].a, 1);
		} else if (r[i].x == 3) {
			add(r[i].b, r[i].a, 1);
		} else if (r[i].x == 5) {
			add(r[i].a, r[i].b, 1);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			dfs(i);
	}
	
	ReBuild();
	Topo();
	
	for (int i = 1; i <= lnk[0]; i++) {
		ans += (candy[i] * siz[i]);
	}
	
	std::cout << ans << "\n";
	
	return 0;
}
