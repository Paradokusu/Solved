#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 N = 1e5 + 5;

struct node {
	i64 tag1, tag2;
};

i64 n, m;

std::array<i64, N> a;
std::array<node, 4 * N> w;

i64 read();
void write(i64 x);

void Update(i64 u, i64 L, i64 R, i64 qL, i64 qR, i64 t1, i64 t2) {
	if (qL <= L && qR >= R) {
		w[u].tag1 += t1, w[u].tag2 += t2;
		return;
	}
	i64 M = (L + R) >> 1;
	if (qL <= M) Update(u << 1, L, M, qL, qR, t1, t2);
	if (qR > M) Update((u << 1) + 1, M + 1, R, qL, qR, t1, t2);
}

i64 Query(i64 u, i64 L, i64 R, i64 Q, i64 t1, i64 t2) {
	if (L == R) return t1 + w[u].tag1 + L * (t2 + w[u].tag2);
	i64 M = (L + R) >> 1;
	if (Q <= M) return Query(u << 1, L, M, Q, t1 + w[u].tag1, t2 + w[u].tag2);
	else return Query((u << 1) + 1, M + 1, R, Q, t1 + w[u].tag1, t2 + w[u].tag2);
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	while (m--) {
		i64 opt = read();
		if (opt == 1) {
			i64 l = read(), r = read(), k = read(), d = read();
			Update(1, 1, n, l, r, k - d * l, d);
		} else {
			i64 q = read();
			write(Query(1, 1, n, q, 0, 0) + a[q]);
			puts("");
		}
	}
	return 0;
}

i64 read(){i64 x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
void write(i64 x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
