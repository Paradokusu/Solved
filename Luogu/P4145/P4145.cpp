// Problem: P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 N = 1e5 + 5;

i64 n, m;
std::array<i64, N> a;
std::array<i64, N * 4> Max, Sum;

i64 read();
void write(i64 x);

bool InRange(i64 L, i64 R, i64 l, i64 r) {
	return (l <= L) && (r >= R);
}

void Pushup(const i64 u) {
	Max[u] = std::max(Max[u << 1], Max[(u << 1) + 1]);
	Sum[u] = Sum[u << 1] + Sum[(u << 1) + 1];
}

void Build(i64 u, i64 L, i64 R) {
	if (L == R) {
		Sum[u] = Max[u] = a[L];
		return;
	}
	
	i64 M = (L + R) >> 1;
	Build(u << 1, L, M);
	Build((u << 1) + 1, M + 1, R);
	Pushup(u);
}

void Update(i64 u, i64 L, i64 R, i64 l, i64 r) {
	if (L == R && InRange(L, R, l, r)) {
		Sum[u] = Max[u] = std::sqrt(Sum[u]);
		return;
	}
	
	i64 M = (L + R) >> 1;
	if (l <= M && Max[u << 1] > 1) Update(u << 1, L, M, l, r);
	if (r > M && Max[(u << 1) + 1] > 1) Update((u << 1) + 1, M + 1, R, l, r);
	Pushup(u);
}

i64 Query(i64 u, i64 L, i64 R, i64 l, i64 r) {
	if (InRange(L, R, l, r)) return Sum[u];
	i64 M = (L + R) >> 1, ans = 0;
	if (l <= M) ans += Query(u << 1, L, M, l, r);
	if (r > M) ans += Query((u << 1) + 1, M + 1, R, l, r);
	return ans;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	Build(1, 1, n);
	m = read();
	while (m--) {
		int op = read(), l = read(), r = read();
		if (l > r) std::swap(l, r);
		switch (op) {
			case 0: {
				Update(1, 1, n, l, r);
				break;
			}
			case 1: {
				write(Query(1, 1, n, l, r));
				puts("");
				break;
			}
		}
	}
	return 0;
}

i64 read(){i64 x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
void write(i64 x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
