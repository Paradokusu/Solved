#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int head[N], to[N << 1], nxt[N << 1], cnt;
void addedge(int b, int e) {
	nxt[++cnt] = head[b];
	to[head[b] = cnt] = e;
}

struct node {
	int x, y;
	char hx, hy;
	
	void read() {
		std::cin >> x >> hx >> y >> hy;
		hx += 'a' - 'A';
		hy += 'a' - 'A';
	}
} R[N << 8];

int n, m, d;
int t0t, tot, idx, top;
int dfn[N], low[N], bel[N];
int stc[N], id[N], seq[10];

bool in[N];

char fir[3] = {'b', 'a', 'a'};
char ava[3][2] = {{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
std::string S;

int Re(int x) {
	return x <= n ? x + n : x - n;
}

void Tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	in[stc[++top] = u] = 1;
	
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (in[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	
	if (low[u] == dfn[u]) {
		int v;
		tot++;
		
		do {
			in[v = stc[top--]] = 0;
			bel[v] = tot;
		} while (v ^ u);
	}
}

void Clean() {
	idx = tot = top = cnt = 0;
	
	for (int i = 1; i <= (n << 1); i++) {
		head[i] = 0;
		low[i] = 0;
		dfn[i] = 0;
		bel[i] = 0;
	}
}

bool Chk() {
	Clean();
	
	for (int i = 1; i <= n; i++) {
		id[i] = S[i] - 'a';
	}
	
	for (int i = 1; i <= m; i++) {
		if (R[i].hx == S[R[i].x])
			continue;
		if (R[i].hy == S[R[i].y]) {
			int p = (R[i].hx == fir[id[R[i].x]] ? R[i].x : Re(R[i].x));
			addedge(p, Re(p));
		} else {
			int p = (R[i].hx == fir[id[R[i].x]] ? R[i].x : Re(R[i].x));
			int q = (R[i].hy == fir[id[R[i].y]] ? R[i].y : Re(R[i].y));
			addedge(p, q);
			addedge(Re(q), Re(p));
		}
	}
	
	for (int i = 1; i <= (n << 1); i++)
		if (!dfn[i])
			Tarjan(i);
	
	for (int i = 1; i <= n; i++)
		if (bel[i] == bel[i + n])
			return 0;
	
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	bool flg = 0;
	
	std::cin >> n >> d;
	std::cin >> S;
	std::cin >> m;
	S = '#' + S;
	
	for (int i = 1; i <= m; i++)
		R[i].read();
	
	for (int i = 1; i <= n; i++) {
		if (S[i] == 'x')
			seq[++t0t] = i;
	}
	
	for (int s = 0; s < (1 << t0t); s++) {
		for (int i = 1; i <= t0t; i++) {
			S[seq[i]] = 'a' + (s >> (i - 1) & 1);
		}
		
		if (flg = Chk())
			break;
	}
	
	if (!flg) {
		std::cout << "-1\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << char(ava[id[i]][bel[i + n] < bel[i]] - 'a' + 'A');
	}
	
	std::cout << "\n";
	return 0;
}