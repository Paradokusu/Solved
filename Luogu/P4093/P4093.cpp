#include <bits/stdc++.h>

#define inline inline __attribute__((always_inline))

using namespace std;
constexpr int N = 1e5 + 5, C = 1e5;

int n, m, ans;
int a[N], f[N], p[N], Max[N], Min[N];

inline bool cmp1(int i, int j) { return Max[i] < Max[j]; }
inline bool cmp2(int i, int j) { return a[i] < a[j]; }

int b[N];
inline int lowbit(int x) { return x & (-x); }
inline void Ins(int i, int x) { for (; i <= C; i += lowbit(i)) b[i] = max(b[i], x); }
inline void Clr(int i) { for (; i <= C; i += lowbit(i)) b[i] = 0; }
inline int Qur(int i) { int A = 0; for (; i; i -= lowbit(i)) A = max(A, b[i]); return A; }

void CDQ(int lb, int rb) {
	if (lb == rb) { f[lb] = max(f[lb], 1); return; }
	int mid = (lb + rb) >> 1;
	CDQ(lb, mid);
	for (int i = lb; i <= rb; i++) p[i] = i;
	sort(p + lb, p + mid + 1, cmp1);
	sort(p + mid + 1, p + rb + 1, cmp2);
	int j = lb;
	for (int i = mid + 1; i <= rb; i++) {
		while (j <= mid && Max[p[j]] <= a[p[i]]) { Ins(a[p[j]], f[p[j]]); ++j; }
		f[p[i]] = max(f[p[i]], Qur(Min[p[i]]) + 1);
	}
	for (int i = lb; i <= mid; i++) Clr(a[i]);
	CDQ(mid + 1, rb);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Max[i] = Min[i] = a[i];
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		Max[l] = max(Max[l], r);
		Min[l] = min(Min[l], r);
	}
	CDQ(1, n);
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
