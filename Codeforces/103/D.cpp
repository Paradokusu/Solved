#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 * 2 + 7;

int n, m, siz;
int a[N];
i64 ans[N], f[N];

struct node {
	int l, r, id;
} q[N];

bool cmp(const node &a, const node &b) {
	return a.r < b.r;
}

void Pre(int pos) {
	memset(f, 0, sizeof(f));
	
	for (int i = n; i; i--) {
		f[i] = f[i + pos] + a[i];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	siz = std::sqrt(n);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	std::cin >> m;
	
	for (int i = 1; i <= m; i++) {
		std::cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	
	std::sort(q + 1, q + m + 1, cmp);
	
	for (int i = 1; i <= m; i++) {
		if (q[i].r != q[i - 1].r && q[i].r <= siz) {
			Pre(q[i].r);
		}
		
		if (q[i].l <= n && q[i].r <= siz) {
			ans[q[i].id] = f[q[i].l];
		} else {
			i64 res = 0;
			
			for (int j = q[i].l; j <= n; j += q[i].r) {
				res += a[j];
			}
			
			ans[q[i].id] = res;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		std::cout << ans[i] << "\n";
	}
	
	return 0;
}
