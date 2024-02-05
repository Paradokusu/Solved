#include <bits/stdc++.h>

using namespace std;

struct node {
	node *ch[2];
	int val, prio;
	int cnt;
	int siz;
	
	node (int _val) : val(_val), cnt(1), siz(1) {
		ch[0] = ch[1] = nullptr;
		prio = rand();
	}
	
	node (node *_node) {
		val = _node -> val, prio = _node -> prio, cnt = _node -> cnt, siz = _node -> siz;
	}
	
	void upd_siz() {
		siz = cnt;
		if (ch[0] != nullptr) siz += ch[0] -> siz;
		if (ch[1] != nullptr) siz += ch[1] -> siz;
	}
};

struct none_rot_treap {
	node *root;
	
	pair<node *, node *> split(node *cur, int key) {
		if (cur == nullptr)
			return {nullptr, nullptr};
		if (cur -> val <= key) {
			auto temp = split(cur -> ch[1], key);
			cur -> ch[1] = temp.first;
			cur -> upd_siz();
			return {cur, temp.second};
		} else {
			auto temp = split(cur -> ch[0], key);
			cur -> ch[0] = temp.second;
			cur -> upd_siz();
			return {temp.first, cur};
		}
	}
	
	tuple<node *, node *, node *> split_by_rk(node *cur, int rk) {
		if (cur == nullptr)
			return {nullptr, nullptr, nullptr};
		int ls_siz = cur -> ch[0] == nullptr ? 0 : cur -> ch[0] -> siz;
		if (rk <= ls_siz) {
			auto [l, mid, r] = split_by_rk(cur -> ch[0], rk);
			cur -> ch[0] = r;
			cur -> upd_siz();
			return {l, mid, cur};
		} else if (rk <= ls_siz + cur -> cnt) {
			node *lt = cur -> ch[0];
			node *rt = cur -> ch[1];
			cur -> ch[0] = cur -> ch[1] = nullptr;
			return {lt, cur, rt};
		} else {
			auto [l, mid, r] = split_by_rk(cur -> ch[1], rk - ls_siz - cur -> cnt);
			cur -> ch[1] = l;
			cur -> upd_siz();
			return {cur, mid, r};
		}
	}
	
	node *merge(node *u, node *v) {
		if (u == nullptr && v == nullptr) return nullptr;
		if (u != nullptr && v == nullptr) return u;
		if (u == nullptr && v != nullptr) return v;
		if (u -> prio < v -> prio) {
			u -> ch[1] = merge(u -> ch[1], v);
			u -> upd_siz();
			return u;
		} else {
			v -> ch[0] = merge(u, v -> ch[0]);
			v -> upd_siz();
			return v;
		}
	}
	
	void insert(int val) {
		auto temp = split(root, val);
		auto l_tr = split(temp.first, val - 1);
		node *new_node;
		if (l_tr.second == nullptr) {
			new_node = new node(val);
		} else {
			l_tr.second -> cnt++;
			l_tr.second -> upd_siz();
		}
		node *l_tr_combined = merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
		root = merge(l_tr_combined, temp.second);
	}
	
	void del(int val) {
		auto temp = split(root, val);
		auto l_tr = split(temp.first, val - 1);
		if (l_tr.second -> cnt > 1) {
			l_tr.second -> cnt--;
			l_tr.second -> upd_siz();
			l_tr.first = merge(l_tr.first, l_tr.second);
		} else {
			if (temp.first == l_tr.second)
				temp.first = nullptr;
			delete l_tr.second;
			l_tr.second = nullptr;
		}
		root = merge(l_tr.first, temp.second);
	}
	
	int qrank_by_val(node *cur, int val) {
		auto temp = split(cur, val - 1);
		int res = (temp.first == nullptr ? 0 : temp.first -> siz) + 1;
		root = merge(temp.first, temp.second);
		return res;
	}
	
	int qval_by_rank(node *cur, int rk) {
		auto [l, mid, r] = split_by_rk(cur, rk);
		int res = mid -> val;
		root = merge(merge(l, mid), r);
		return res;
	}
	
	int qprev(int val) {
		auto temp = split(root, val - 1);
		int res = qval_by_rank(temp.first, temp.first -> siz);
		root = merge(temp.first, temp.second);
		return res;
	}
	
	int qnex(int val) {
		auto temp = split(root, val);
		int res = qval_by_rank(temp.second, 1);
		root = merge(temp.first, temp.second);
		return res;
	}
} tr;

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

int main() {
	mt19937 rand(time(nullptr));
	
	int t = read<int>();
	while (t--) {
		int mode = read<int>(), num = read<int>();
		
		switch (mode) {
			case 1:
				tr.insert(num);
				break;
			case 2:
				tr.del(num);
				break;
			case 3:
				write<int>(tr.qrank_by_val(tr.root, num));
				puts("");
				break;
			case 4:
				write<int>(tr.qval_by_rank(tr.root, num));
				puts("");
				break;
			case 5:
				write<int>(tr.qprev(num));
				puts("");
				break;
			case 6:
				write<int>(tr.qnex(num));
				puts("");
				break;
		}
	}
	return 0;
}
