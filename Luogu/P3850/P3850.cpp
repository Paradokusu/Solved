#include <bits/stdc++.h>

constexpr int N = 2e6 + 7;

int n, m, cnt;
int rt, r1, r2, r3, r4;

struct fhq_treap {
	int ch[2];
	int siz, val, prio;
} t[N << 1];

std::string s[N];

void Pushup(int x) {
	t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
}

int Newnode(int x) {
	t[++cnt].siz = 1;
	t[cnt].val = x;
	t[cnt].prio = rand();
	return cnt;
}

void Split(int o, int v, int &x, int &y) {
	if (!o)
		x = y = 0;
	else {
		if (v <= t[t[o].ch[0]].siz) {
			y = o;
			Split(t[o].ch[0], v, x, t[o].ch[0]);
		} else {
			x = o;
			Split(t[o].ch[1], v - t[t[o].ch[0]].siz - 1, t[o].ch[1], y);
		}
		
		Pushup(o);
	}
}

int Merge(int x, int y) {
	if (!x || !y)
		return x + y;
	if (t[x].prio < t[y].prio) {
		t[x].ch[1] = Merge(t[x].ch[1], y);
		Pushup(x);
		return x;
	}
	
	t[y].ch[0] = Merge(x, t[y].ch[0]);
	Pushup(y);
	return y;
}

void Insert(int v, int id) {
	Split(rt, v, r1, r2);
	rt = Merge(r1, Merge(Newnode(id), r2));
}

void Query(int v) {
	Split(rt, v, r1, r2);
	Split(r2, 1, r3, r4);
	std::cout << s[t[r3].val] << "\n";
	rt = Merge(r1, Merge(r3, r4));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::mt19937 rand(time(nullptr));
	
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[++cnt];
		Insert(i - 1, cnt);
	}
	
	std::cin >> m;
	while (m--) {
		int x;
		std::cin >> s[++cnt] >> x;
		Insert(x, cnt);
	}
	
	std::cin >> m;
	while (m--) {
		int x;
		std::cin >> x;
		Query(x);
	}
	
	return 0;
}
