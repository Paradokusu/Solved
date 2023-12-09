// Problem: P5522 [yLOI2019] 棠梨煎雪
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5522
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

int n, m, q;
int check, ans1, ans2, sum, ans;	// ans1 代表某一位是否确定，ans2 表示确定后该位为 0 还是 1

std::array<int, 4 * N> vis, t1, t2;

bool Out(int X1, int X2, int Y1, int Y2) {
	for (int i = 0; i < n; i++) {
		if (!(X1 & (1 << i)) || !(Y1 & (1 << i))) continue;
		if ((X2 & (1 << i)) != (Y2 & (1 << i))) return true;
	}
	return false;
}

void Update(int u, int L, int R, int x, std::string & c) {
	if (L > x || R < x) return;
	if (L == R && L == x) {
		vis[u] = t1[u] = t2[u] = 0;
		for (int i = 0; i < n; i++) {
			if (c[i] != '?') {
				t1[u] |= 1 << i;
				if (c[i] == '1') t2[u] |= 1 << i;
			}
		}
		return;
	}
	int M = (L + R) / 2;
	Update(u * 2, L, M, x, c);
	Update(u * 2 + 1, M + 1, R, x, c);
	L = u * 2, R = u * 2 + 1;
	if ((vis[L] | vis[R]) || Out(t1[L], t2[L], t1[R], t2[R])) {
		vis[u] = 1;
		return;
	}
	vis[u] = 0;
	t1[u] = t1[L] | t1[R];
	t2[u] = t2[L] | t2[R];
}

void Query(int u, int L, int R, int x, int y) {
	if (L > y || R < x) return;
	if (x <= L && R <= y) {
		if (vis[u] || Out(ans1, ans2, t1[u], t2[u])) {
			check = 1;
			return;
		}
		ans1 |= t1[u], ans2 |= t2[u];
		return;
	}
	int M = (L + R) / 2;
	Query(u * 2, L, M, x, y);
	Query(u * 2 + 1, M + 1, R, x, y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		std::string c;
		std::cin >> c;
		Update(1, 1, m, i, c);
	}
	while (q--) {
		int op;
		std::cin >> op;
		switch (op) {
			case 0: {
				check = ans1 = ans2 = 0, sum = 1;
				int l, r;
				std::cin >> l >> r;
				Query(1, 1, m, l, r);
				if (check) break;
				for (int i = 0; i < n; i++)
					if (!(ans1 & (1 << i))) sum *= 2;
				ans ^= sum;
				break;
			}
			case 1: {
				int pos;
				std::string c;
				std::cin >> pos >> c;
				Update(1, 1, m, pos, c);
				break;
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}
