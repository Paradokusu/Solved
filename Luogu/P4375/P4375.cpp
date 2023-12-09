#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

int n, c[N];

struct node {
	int val, pos;
} p[N];

bool cmp1(const node x, const node y) { if (x.val == y.val) return x.pos < y.pos; return x.val < y.val; }
bool cmp2(const node x, const node y) { return x.pos < y.pos; }

int lowbit(int x) { return x & (-x); }
void Add(int i) { for (; i <= n; i += lowbit(i)) c[i]++; }
int Sum(int i) { int res = 0; for (; i; i -= lowbit(i)) res += c[i]; return res; }

int main() {
	scanf("%d", &n);
	for (int i = 1, in; i <= n; i++) { scanf("%d", &in); p[i] = {in, i}; }
	sort(p + 1, p + n + 1, cmp1);
	for (int i = 1; i <= n; i++) p[i].val = i;
	sort(p + 1, p + n + 1, cmp2);
	int ans = 1;
	for (int i = 1; i <= n; i++) { Add(p[i].val); ans = max(ans, i - Sum(i)); }
	printf("%d\n", ans);
	return 0;
}
