#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, v;
int c1, c2, tot1, tot2;
i64 ans, res;
i64 pre[N];

struct node {
	int val, id;
} a[N], b[N];

bool cmp(const node &a, const node &b) {
	return a.val > b.val;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> v;
	
	for (int i = 1; i <= n; i++) {
		int type, val;
		std::cin >> type >> val;
		
		if (type == 1)
			a[++tot1] = {val, i};
		else
			b[++tot2] = {val, i};
	}
	
	std::sort(a + 1, a + tot1 + 1, cmp);
	std::sort(b + 1, b + tot2 + 1, cmp);
	
	for (int i = 1; i <= tot2; i++) {
		pre[i] = pre[i - 1] + b[i].val;
	}
	
	for (int i = 0; i <= tot1 && i <= v; i++) {
		int p = std::min((v - i) / 2, tot2);
		res += a[i].val;
		
		if (res + pre[p] > ans) {
			ans = res + pre[p];
			c1 = i, c2 = p;
		}
	}
	
	std::cout << ans << "\n";
	
	for (int i = 1; i <= c1; i++)
		std::cout << a[i].id << " ";
	
	for (int i = 1; i <= c2; i++)
		std::cout << b[i].id << " ";
	
	return 0;
}
