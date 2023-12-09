// Problem: P1253 扶苏的问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1253
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 N = 1e6 + 5;
constexpr i64 inf = 1e18;
i64 n, m;
std::array<i64, N> a;
std::array<i64, 4 * N> w, lzy_add, lzy_set;

bool InRange(i64 L, i64 R, i64 l, i64 r) {
	return (l <= L) && (r >= R);
}

i64 read();
void write(i64 x);

bool OutOfRange(i64 L, i64 R, i64 l, i64 r) {
	return (R < l) || (L > r);
}

void Pushup(const i64 u) {
	w[u] = std::max(w[u * 2], w[u * 2 + 1]);
}

void Maketag(i64 u, i64 x, i64 type) {
	if (type == 1) lzy_add[u] = 0, lzy_set[u] = x, w[u] = x;
	else {
		if (lzy_set[u] == inf) lzy_add[u] += x;
		else lzy_set[u] += x;
		w[u] += x;
	}
}

void Pushdown(i64 u) {
	if (lzy_set[u] == inf) {
		Maketag(u * 2, lzy_add[u], 2);
		Maketag(u * 2 + 1, lzy_add[u], 2);
		lzy_add[u] = 0;
	} else {
		Maketag(u * 2, lzy_set[u], 1);
		Maketag(u * 2 + 1, lzy_set[u], 1);
		lzy_set[u] = inf;
	}
}

void Build(i64 u, i64 L, i64 R) {
	if (L == R) {
		w[u] = a[L];
		return;
	}
	i64 M = (L + R) / 2;
	Build(u * 2, L, M);
	Build(u * 2 + 1, M + 1, R);
	Pushup(u);
	lzy_set[u] = inf;
}

void Update(i64 u, i64 L, i64 R, i64 l, i64 r, i64 x, i64 type) {
	if (type == 1) {
		if (InRange(L, R, l, r)) Maketag(u, x, 1);
		else if (!OutOfRange(L, R, l, r)) {
			i64 M = (L + R) / 2;
			Pushdown(u);
			Update(u * 2, L, M, l, r, x, 1);
			Update(u * 2 + 1, M + 1, R, l, r, x, 1);
			Pushup(u);
		}
	} else if (type == 2) {
		if (InRange(L, R, l, r)) Maketag(u, x, 2);
		else if (!OutOfRange(L, R, l, r)) {
			i64 M = (L + R) / 2;
			Pushdown(u);
			Update(u * 2, L, M, l, r, x, 2);
			Update(u * 2 + 1, M + 1, R, l, r, x, 2);
			Pushup(u);
		}
	}
}

i64 Query(i64 u, i64 L, i64 R, i64 l, i64 r) {
	if (InRange(L, R, l, r)) return w[u];
	else if (!OutOfRange(L, R, l, r)) {
		i64 M = (L + R) / 2;
		Pushdown(u);
		return std::max(Query(u * 2, L, M, l, r), Query(u * 2 + 1, M + 1, R, l, r));
	} else return -inf;
}

int main() {
	n = read(), m = read();
	for (i64 i = 1; i <= n; i++)
		a[i] = read();
	Build(1, 1, n);
	while (m--) {
		i64 op = read();
		if (op == 1) {
			i64 l = read(), r = read(), x = read();
			Update(1, 1, n, l, r, x, 1);
		} else if (op == 2) {
			i64 l = read(), r = read(), x = read();
			Update(1, 1, n, l, r, x, 2);
		} else if (op == 3) {
			i64 l = read(), r = read();
			write(Query(1, 1, n, l, r));
			puts("");
		}
	}
	return 0;
}

i64 read(){i64 x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
void write(i64 x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
