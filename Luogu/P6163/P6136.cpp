#include <bits/stdc++.h>

using namespace std;
namespace SplayTree {
	constexpr int SIZ = 1e6 + 1e5 + 7;
	
	int idx;
	int F[SIZ], C[SIZ], S[SIZ], W[SIZ], X[SIZ][2];
	
	bool IsRoot(int x) { return F[x] == 0; }
	bool IsRson(int x) { return X[F[x]][1] == x; }
	
	int NewNode (int w) {
		W[++idx] = w;
		C[idx] = S[idx] = 1;
		F[idx] = 0;
		
		return idx;
	}
	
	void Pushup(int x) {
		S[x] = C[x] + S[X[x][0]] + S[X[x][1]];
	}
	
	void Rorate(int x) {
		int y = F[x], z = F[y];
		bool f = IsRson(x), g = IsRson(y);
		int &rt = X[x][!f];
		
		if (z) X[z][g] = x;
		if (rt) F[rt] = y;
		
		X[y][f] = rt;
		rt = y;
		
		F[y] = x;
		Pushup(y);
		
		F[x] = z;
		Pushup(x);
	}
	
	void Splay(int &rt, int x) {
		for (int f = F[x]; f = F[x], f; Rorate(x))
			if (F[f])
				Rorate(IsRson(x) == IsRson(f) ? f : x);
		rt = x;
	}
	
	void Insert(int &rt, int w) {
		if (rt == 0) { rt = NewNode(w); return; }
		int x = rt, o = x;
		
		for (; x; o = x, x = X[x][w > W[x]]) {
			++S[x];
			if (w == W[x]) {
				++C[x], o = x;
				break;
			}
		}
		
		if (W[o] != w) {
			if (w < W[o]) {
				X[o][0] = NewNode(w);
				F[idx] = o;
				o = idx;
			} else {
				X[o][1] = NewNode(w);
				F[idx] = o;
				o = idx;
			}
		}
		
		Splay(rt, o);
	}
	
	void Erase(int &rt, int w) {
		int val = S[rt];
		int x = rt, o = x;
		
		for (; x; o = x, x = X[x][w > W[x]]) {
			--S[x];
			if (w == W[x]) {
				--C[x];
				o = x;
				break;
			}
		}
		
		Splay(rt, o);
		
		if (C[o] == 0) {
			if (X[o][0] == 0 || X[o][1] == 0) {
				int u = X[o][0] | X[o][1];
				if (u != 0)
					F[rt = u] = 0;
			} else {
				int p = X[o][0];
				F[p] = 0;
				int q = X[o][0];
				
				while (X[q][1])
					q = X[q][1];
				
				Splay(p, q);
				X[q][1] = X[o][1];
				F[X[o][1]] = q;
				Pushup(q);
				rt = q;
			}
		}
	}
	
	int FindRank(int &rt, int w) {
		int x = rt, o = x, a = 0;
		
		for (; x;) {
			if (w < W[x])
				o = x, x = X[x][0];
			else {
				a += S[X[x][0]];
				
				if (w == W[x]) {
					o = x;
					break;
				}
				
				a += C[x];
				o = x;
				x = X[x][1];
			}
		}
		
		Splay(rt, o);
		return a + 1;
	}
	
	int FindKth(int &rt, int w) {
		int x = rt, o = x, a = 0;
		
		for (; x;) {
			if (w <= S[X[x][0]])
				o = x, x = X[x][0];
			else {
				w -= S[X[x][0]];
				
				if (w <= C[x]) {
					o = x;
					break;
				}
				
				w -= C[x];
				o = x;
				x = X[x][1];
			}
		}
		
		Splay(rt, o);
		return W[x];
	}
	
	int FindPre(int &rt, int w) {
		return FindKth(rt, FindRank(rt, w) - 1);
	}
	
	int FindSuc(int &rt, int w) {
		return FindKth(rt, FindRank(rt, w + 1));
	}
}

template <typename T> T read() {
	T sum = 0, fl = 1;  // 将 sum,fl 和 ch 以输入的类型定义
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
	using namespace SplayTree;
	
	int root = 0;
	int n = read<int>(), m = read<int>();
	for (int i = 1; i <= n; i++) {
		int in = read<int>();
		Insert(root, in);
	}
	
	int last_ans = 0, ans = 0;
	while (m--) {
		int op = read<int>(), in = read<int>();
		int	x = in ^ last_ans;
		
		switch (op) {
			case 1 : Insert(root, x); break;
			case 2 : Erase(root, x); break;
			case 3 : ans ^= (last_ans = FindRank(root, x)); break;
			case 4 : ans ^= (last_ans = FindKth(root, x)); break;
			case 5 : ans ^= (last_ans = FindPre(root, x)); break;
			case 6 : ans ^= (last_ans = FindSuc(root, x)); break;
		}
	}
	
	write<int>(ans);
	puts("");
	return 0;
}
