// Problem: P1966 [NOIP2013 提高组] 火柴排队
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1966
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 5;
constexpr int MOD = 1e8 - 3;

int n, ans;
std::array<i64, N> x, c;

struct node {
	i64 val, num;
	
	friend bool operator < (node x, node y) {
		if (x.val == y.val) return x.num < y.num;
		return x.val < y.val;
	}
};

std::array<node, N> a, b;

i64 read();
void write(i64 x);

i64 lowbit(int x) { return x & (-x); }

i64 Sum(int x) {
	i64 res = 0;
	for (int i = x; i; i -= lowbit(i)) res += c[i], res %= MOD;
	return res;
}

void Add(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i)) c[i] += y, c[i] %= MOD;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i].val = read(), a[i].num = i;
	for (int i = 1; i <= n; i++) b[i].val = read(), b[i].num = i;
	std::sort(a.begin() + 1, a.begin() + n + 1);
	std::sort(b.begin() + 1, b.begin() + n + 1);
	for (int i = 1; i <= n; i++) x[a[i].num] = b[i].num;
	for (int i = 1; i <= n; i++) {
		Add(x[i], 1);
		ans += i - Sum(x[i]);
		ans %= MOD;
	}
	write(ans);
	return 0;
}

i64 read() { i64 x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); } while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); } return x*f; }
void write(i64 x) { if(x<0) putchar('-'),x=-x; if(x>9) write(x/10); putchar(x%10+'0'); }
