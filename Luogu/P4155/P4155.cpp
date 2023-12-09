#include <bits/stdc++.h>

using namespace std;
constexpr int N = 4e5 + 5;

struct node {
	int id, lf, rg;
	bool operator < (const node &a) const {
		return lf < a.lf;
	}
} p[N];

int n, m, tn;
int res[N], go[N][35];

void init() {
	int nxt = 1;
	for (int i = 1; i <= tn; i++) {
		while (nxt <= tn && p[nxt].lf <= p[i].rg) nxt++;
		go[i][0] = nxt - 1;
	}
	for (int i = 1; (1 << i) <= n; i++) {
		for (int s = 1; s <= tn; s++)
			go[s][i] = go[go[s][i - 1]][i - 1];
	}
}

void find(int x) {
	int len = p[x].lf + m, cur = x, ans = 1;
	for (int i = 29; i >= 0; i--) {
		int pos = go[cur][i];
		if (pos && p[pos].rg < len) ans += (1 << i), cur = pos;
	}
	res[p[x].id] = ans + 1;
}

int main() {
	scanf("%d %d", &n, &m);
	tn = n;
	for (int i = 1; i <= n; i++) {
		p[i].id = i;
		scanf("%d %d", &p[i].lf, &p[i].rg);
		if (p[i].lf > p[i].rg) p[i].rg += m;	// 化圆为直
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
		tn++, p[tn] = p[i], p[tn].lf += m, p[tn].rg += m;
	init();	// 预处理倍增表
	for (int i = 1; i <= n; i++) find(i);
	for (int i = 1; i <= n; i++) printf("%d ", res[i]);
	return 0;
}
