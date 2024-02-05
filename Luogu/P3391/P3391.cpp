#include <bits/stdc++.h>

using namespace std;

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

struct node {
	node *ch[2];
	int val, prio;
	int cnt;
	int siz;
	bool to_rev= 0;
	
	node(int _val) : val(_val), cnt(1), siz(1) {
		ch[0] = ch[1] = nullptr;
		prio = rand();
	}
	
	int upd_siz() {
		siz = cnt;
		if (ch[0] != nullptr) siz += ch[0] -> siz;
		if (ch[1] != nullptr) siz += ch[1] -> siz;
		return siz;
	}
	
	void pushdown() {
		swap(ch[0], ch[1]);
		if (ch[0] != nullptr) ch[0] -> to_rev ^= 1;
		if (ch[1] != nullptr) ch[1] -> to_rev ^= 1;
		to_rev = 0;
	}
	
	void check_tag() {
		if (to_rev)
			pushdown();
	}
};

struct seg_treap {
	node *root;
	#define siz(x) (x == nullptr ? 0 : x -> siz)
	
	pair<node*, node*> split(node *cur, int sz) {
		if (cur == nullptr) return {nullptr, nullptr};
		cur -> check_tag();
		if (sz <= siz(cur -> ch[0])) {
			auto temp = split(cur -> ch[0], sz);
			cur -> ch[0] = temp.second;
			cur -> upd_siz();
			return {temp.first, cur};
		} else {
			auto temp = split(cur -> ch[1], sz - siz(cur -> ch[0]) - 1);
			cur -> ch[1] = temp.first;
			cur -> upd_siz();
			return {cur, temp.second};
		}
	}
	
	node* merge(node *sm, node *bg) {
		if (sm == nullptr && bg == nullptr) return nullptr;
		if (sm != nullptr && bg == nullptr) return sm;
		if (sm == nullptr && bg != nullptr) return bg;
		sm -> check_tag(), bg -> check_tag();
		if (sm -> prio < bg -> prio) {
			sm -> ch[1] = merge(sm -> ch[1], bg);
			sm -> upd_siz();
			return sm;
		} else {
			bg -> ch[0] = merge(sm, bg -> ch[0]);
			bg -> upd_siz();
			return bg;
		}
	}
	
	void insert(int val) {
		auto temp = split(root, val);
		auto l_tr = split(temp.first, val - 1);
		node *new_node;
		if (l_tr.second == nullptr) new_node = new node(val);
		node *l_tr_combined = merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
		root = merge(l_tr_combined, temp.second);
	}
	
	void seg_rev(int l, int r) {
		auto less = split(root, l - 1);
		auto more = split(less.second, r - l + 1);
		more.first -> to_rev = 1;
		root = merge(less.first, merge(more.first, more.second));
	}
	
	void print(node *cur) {
		if (cur == nullptr)
			return;
		cur -> check_tag();
		print(cur -> ch[0]);
		write<int>(cur -> val);
		putchar(' ');
		print(cur -> ch[1]);
	}
} tr;

int main() {
	mt19937 rand(time(nullptr));
	
	int n = read<int>(), m = read<int>();
	for (int i = 1; i <= n; i++)
		tr.insert(i);
	while (m--) {
		int l = read<int>(), r = read<int>();
		tr.seg_rev(l, r);
	}
	tr.print(tr.root);
	return 0;
}
