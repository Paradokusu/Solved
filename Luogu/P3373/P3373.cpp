#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 5;

int n, q, m;
std::array<int, N> a;
std::array<i64, 4 * N> lzy_add, lzy_mul, w;

int read();
void write(i64 x);

bool InRange(int L, int R, int l, int r) {
	return (l <= L) && (r >= R);
}

bool OutOfRange(int L, int R, int l, int r) {
	return (L > r) || (R < l);
}

void Maketag(int u, int L, int R, i64 x, int type) {
	if (type == 1) {
		(lzy_add[u] *= x) %= m;
		(lzy_mul[u] *= x) %= m;
		(w[u] *= x) %= m;
	} else {
		(lzy_add[u] += x) %= m;
		(w[u] += (R - L + 1) * x) %= m;
	}
}

void Pushdown(int u, int L, int R) {
	int M = (L + R) / 2;
	Maketag(u * 2, L, M, lzy_mul[u], 1);
	Maketag(u * 2, L, M, lzy_add[u], 2);
	Maketag(u * 2 + 1, M + 1, R, lzy_mul[u], 1);
	Maketag(u * 2 + 1, M + 1, R, lzy_add[u], 2);
	lzy_mul[u] = 1, lzy_add[u] = 0;
}

void Pushup(const int u) {
	w[u] = (w[u * 2] + w[u * 2 + 1]) % m;
}

void Build(int u, int L, int R) {
	if (L == R) {
		w[u] = a[L];
		return;
	}
	
	int M = (L + R) / 2;
	Build(u * 2, L, M);
	Build(u * 2 + 1, M + 1, R);
	Pushup(u);
	lzy_mul[u] = 1;
}

void Update(int u, int L, int R, int l, int r, i64 x, int type) {
	if (InRange(L, R, l, r)) Maketag(u, L, R, x, type);
	else if (!OutOfRange(L, R, l, r)) {
		int M = (L + R) / 2;
		Pushdown(u, L, R);
		Update(u * 2, L, M, l, r, x, type);
		Update(u * 2 + 1, M + 1, R, l, r, x, type);
		Pushup(u);
	}
}

i64 Query(int u, int L, int R, int l, int r) {
	if (InRange(L, R, l, r)) return w[u];
	else if (!OutOfRange(L, R, l, r)) {
		int M = (L + R) / 2;
		Pushdown(u, L, R);
		return (Query(u * 2, L, M, l, r) + Query(u * 2 + 1, M + 1, R, l, r)) % m;
	} else return 0;
}

int main() {
	n = read(), q = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	Build(1, 1, n);
	while (q--) {
		int op = read();
		if (op == 1) {
			int x = read(), y = read(), k = read();
			Update(1, 1, n, x, y, k, 1);
		} else if (op == 2) {
			int x = read(), y = read(), k = read();
			Update(1, 1, n, x, y, k, 2);
		} else if (op == 3) {
			int x = read(), y = read();
			write(Query(1, 1, n, x, y));
			puts("");
		}
	}
	return 0;
}

int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
void write(i64 x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
