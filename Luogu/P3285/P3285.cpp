#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, m;
int root, cnt, ans;

struct node {
	int fa, siz, l, r;
	int ch[2];
} t[N << 1];

map<int, int> f;

void Init() {
	root = cnt = 1;
	t[root].l = 1, t[root].r = n;
	t[root].siz = n;
	f[n] = 1;
}

void Pushup(int x) {
	t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + (t[x].r - t[x].l + 1);
}

void Rorate(int x) {
	int y = t[x].fa, z = t[y].fa;
	int p = t[y].ch[1] == x;
	t[x].fa = z;
	if (z)
		t[z].ch[t[z].ch[1] == y] = x;
	t[y].ch[p] = t[x].ch[!p];
	t[t[y].ch[p]].fa = y;
	t[y].fa = x;
	t[x].ch[!p] = y;
	Pushup(y);
}

void Splay(int x, int to) {
	while (t[x].fa != to) {
		int y = t[x].fa, z = t[y].fa;
		if (z != to) {
			if ((t[z].ch[0] == y) ^ (t[y].ch[0] == x))
				Rorate(x);
			else
				Rorate(y);
		}
		Rorate(x);
	}
	
	Pushup(x);
	if (to == 0)
		root = x;
}

int Query(int x) {
	Splay(x, 0);
	return t[x].siz - t[t[x].ch[1]].siz;
}

int Getkth(int k) {
	int x = root;
	while (k) {
		int sum = t[t[x].ch[0]].siz + (t[x].r - t[x].l + 1);
		if (t[t[x].ch[0]].siz < k && k <= sum) {
			k -= t[t[x].ch[0]].siz;
			break;
		}
		if (sum < k) {
			k -= sum;
			x = t[x].ch[1];
		} else
			x = t[x].ch[0];
	}
	
	return t[x].l + k - 1;
}

void Erase(int x) {
	int pre = t[x].ch[0], nxt = t[x].ch[1];
	while (t[pre].ch[1])
		pre = t[pre].ch[1];
	while (t[nxt].ch[0])
		nxt = t[nxt].ch[0];
	if (!pre && !nxt)
		root = 0;
	else if (!pre) {
		Splay(nxt, root);
		root = nxt;
		t[root].fa = 0;
		t[x].ch[0] = t[x].ch[1] = 0;
		t[x].siz = 1;
	} else if (!nxt) {
		Splay(pre, root);
		root = pre;
		t[root].fa = 0;
		t[x].ch[0] = t[x].ch[1] = 0;
		t[x].siz = 1;
	} else {
		Splay(pre, 0);
		Splay(nxt, pre);
		t[nxt].ch[0] = t[x].fa = 0;
		t[x].siz = 1;
		Pushup(nxt);
		Pushup(pre);
	}
}

void Push_front(int x) {
	if (!root) { root = x; return; }
	int pt = root;
	while (t[pt].ch[0]) {
		t[pt].siz++;
		pt = t[pt].ch[0];
	}
	t[pt].siz++;
	t[pt].ch[0] = x;
	t[x].fa = pt;
	Splay(x, 0);
}

void Push_back(int x) {
	if (!root) { root = x; return; }
	int pt = root;
	while (t[pt].ch[1]) {
		t[pt].siz++;
		pt = t[pt].ch[1];
	}
	t[pt].siz++;
	t[pt].ch[1] = x;
	t[x].fa = pt;
	Splay(x, 0);
}

void Split(int x, int id) {
	int L = t[x].l, R = t[x].r, ls, rs;
	if (L == R) return;
	if (L == id) {
		rs = ++cnt;
		f[R] = rs, f[id] = x;
		t[rs].ch[1] = t[x].ch[1];
		t[t[rs].ch[1]].fa = rs;
		t[x].ch[1] = rs;
		t[rs].fa = x;
		t[rs].l = L + 1;
		t[rs].r = R;
		t[x].r = L;
		Pushup(rs);
		Pushup(x);
	} else if (R == id) {
		ls = ++cnt;
		f[R - 1] = ls, f[id] = x;
		t[ls].ch[0] = t[x].ch[0];
		t[t[ls].ch[0]].fa = ls;
		t[x].ch[0] = ls;
		t[ls].fa = x;
		t[ls].l = L;
		t[ls].r = R - 1;
		t[x].l = R;
		Pushup(ls);
		Pushup(x);
	} else {
		ls = ++cnt, rs = ++cnt;
		f[id] = x;
		f[id - 1] = ls;
		f[R] = rs;
		t[ls].ch[0] = t[x].ch[0];
		t[rs].ch[1] = t[x].ch[1];
		t[t[ls].ch[0]].fa = ls;
		t[t[rs].ch[1]].fa = rs;
		t[x].ch[0] = ls;
		t[x].ch[1] = rs;
		t[ls].fa = t[rs].fa = x;
		t[x].l = t[x].r = id;
		t[ls].l = L;
		t[ls].r = id - 1;
		t[rs].l = id + 1;
		t[rs].r = R;
		Pushup(ls);
		Pushup(rs);
		Pushup(x);
	}
	
	Splay(x, 0);
}

int main() {
	scanf("%d %d", &n, &m);
	Init();
	
	while (m--) {
		int opt, a, b;
		scanf("%d", &opt);
		
		if (opt == 1) {
			scanf("%d %d", &a, &b);
			int sid = a - ans, eid = b - ans;
			int x = f.lower_bound(sid) -> second;
			Split(x, sid);
			ans = Query(x);
			t[x].l = t[x].r = eid;
			f[eid] = x;
			printf("%d\n", ans);
		} else if (opt == 2) {
			scanf("%d", &a);
			int id = a - ans;
			int x = f.lower_bound(id) -> second;
			Split(x, id);
			ans = Query(x);
			Erase(x);
			Push_front(x);
			printf("%d\n", ans);
		} else if (opt == 3) {
			scanf("%d", &a);
			int id = a - ans;
			int x = f.lower_bound(id) -> second;
			Split(x, id);
			ans = Query(x);
			Erase(x);
			Push_back(x);
			printf("%d\n", ans);
		} else if (opt == 4) {
			scanf("%d", &a);
			int k = a - ans;
			ans = Getkth(k);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
