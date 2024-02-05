#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 7;
constexpr i64 inf = 2147483647;

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, cnt;
int rot[N];

struct node {
	int siz, prio, ch[2];
	i64 w;
} tr[N << 8];

void update(int rt) {
	tr[rt].siz = 1;
	if (tr[rt].ch[0])
		tr[rt].siz += tr[tr[rt].ch[0]].siz;
	if (tr[rt].ch[1])
		tr[rt].siz += tr[tr[rt].ch[1]].siz;
}

int newnode(i64 w = 0) {
	tr[++cnt].w = w;
	tr[cnt].siz = 1;
	tr[cnt].prio = rand();
	return cnt;
}

int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (tr[x].prio < tr[y].prio) {
		int rt = newnode();
		tr[rt] = tr[x];
		tr[rt].ch[1] = merge(tr[rt].ch[1], y);
		update(rt);
		return rt;
	} else {
		int rt = newnode();
		tr[rt] = tr[y];
		tr[rt].ch[0] = merge(x, tr[rt].ch[0]);
		update(rt);
		return rt;
	}
}

void split(int rt, i64 k, int &x, int &y) {
	if (!rt) x = y = 0;
	else {
		if (tr[rt].w <= k) {
			x = newnode();
			tr[x] = tr[rt];
			split(tr[x].ch[1], k, tr[x].ch[1], y);
			update(x);
		} else {
			y = newnode();
			tr[y] = tr[rt];
			split(tr[y].ch[0], k, x, tr[y].ch[0]);
			update(y);
		}
	}
}

int findkth(int rt, int k) {
	while (1) {
		if (k <= tr[tr[rt].ch[0]].siz)
			rt = tr[rt].ch[0];
		else {
			if (tr[rt].ch[0])
				k -= tr[tr[rt].ch[0]].siz;
			if (!(--k)) return rt;
			rt = tr[rt].ch[1];
		}
	}
}

int main() {
	mt19937 rand(time(nullptr));
	
	n = read<int>();
	
	for (int i = 1; i <= n; i++) {
		int fx = 0, fy = 0, fz = 0;
		int v = read<int>(), op = read<int>();
		i64 x = read<i64>();
		rot[i] = rot[v];
		
		if (op == 1) {
			split(rot[i], x, fx, fy);
			rot[i] = merge(merge(fx, newnode(x)), fy);
		} else if (op == 2) {
			split(rot[i], x, fx, fz);
			split(fx, x - 1, fx, fy);
			fy = merge(tr[fy].ch[0], tr[fy].ch[1]);
			rot[i] = merge(merge(fx, fy), fz);
		} else if (op == 3) {
			split(rot[i], x - 1, fx, fy);
			write<i64>(tr[fx].siz + 1);
			puts("");
			rot[i] = merge(fx, fy);
		} else if (op == 4) {
			write<int>(tr[findkth(rot[i], x)].w);
			puts("");
		} else if (op == 5) {
			split(rot[i], x - 1, fx, fy);
			if (fx == 0) {
				write<i64>(inf);
				puts("");
				continue;
			}
			
			write<i64>(tr[findkth(fx, tr[fx].siz)].w);
			puts("");
			rot[i] = merge(fx, fy);
		} else if (op == 6) {
			split(rot[i], x, fx, fy);
			if (fy == 0) {
				write<i64>(inf);
				puts("");
				continue;
			}
			
			write<i64>(tr[findkth(fy, 1)].w);
			puts("");
			rot[i] = merge(fx, fy);
		}
	}
	
	return 0;
}
