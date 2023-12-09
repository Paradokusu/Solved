#include <bits/stdc++.h>

constexpr int N = 6e5 + 5;

int n, q;
int a[N], s[N];

struct Trie {
	int cnt;
	int rt[N], val[33 * N], ch[33 * N][2];
	
	void insert(int o, int lst, int v) {
		for (int i = 28; i >= 0; i--) {
			val[o] = val[lst] + 1;	// 在原来的版本上更新
			if ((v & (1 << i)) == 0) {
				if (!ch[o][0]) ch[o][0] = ++cnt;
				ch[o][1] = ch[lst][1];
				o = ch[o][0];
				lst = ch[lst][0];
			} else {
				if (!ch[o][1]) ch[o][1] = ++cnt;
				ch[o][0] = ch[lst][0];
				o = ch[o][1];
				lst = ch[lst][1];
			}
		}
		val[o] = val[lst] + 1;
	}
	
	int query(int o1, int o2, int v) {
		int res = 0;
		for (int i = 28; i >= 0; i--) {
			int t = ((v & (1 << i)) ? 1 : 0);
			if (val[ch[o1][!t]] - val[ch[o2][!t]])
				res += (1 << i), o1 = ch[o1][!t], o2 = ch[o2][!t];	// 尽量往不同方向跳
			else
				o1 = ch[o1][t], o2 = ch[o2][t];
		}
		return res;
	}
} st;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
		st.rt[i] = ++st.cnt, st.insert(st.rt[i], st.rt[i - 1], s[i]);
	while (q--) {
		char op;
		scanf(" %c", &op);
		if (op == 'A') {
			n++;
			scanf("%d", &a[n]);
			s[n] = s[n - 1] ^ a[n];
			st.rt[n] = ++st.cnt;
			st.insert(st.rt[n], st.rt[n - 1], s[n]);
		} else if (op == 'Q') {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			l--, r--;
			if (l == 0) printf("%d\n", std::max(s[n] ^ x, st.query(st.rt[r], st.rt[0], s[n] ^ x)));
			else printf("%d\n", st.query(st.rt[r], st.rt[l - 1], s[n] ^ x));
		}
	}
	return 0;
}
