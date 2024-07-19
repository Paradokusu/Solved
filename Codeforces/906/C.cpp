#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 22;
constexpr int S = 1007;
constexpr int inf = 0x3f3f3f3f;

int n, m;
int a[N + 7];
int f[(1 << N) + S], q[(1 << N) + S];	// dp 数组和经谁介绍后到的状态
int fa[(1 << N) + S];

void find(int x) {
	if (fa[x]) find(fa[x]);
	std::cout << q[x] << " ";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	memset(f, 0x3f, sizeof(f));
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = 1 << (i - 1);	// 自己和自己
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		a[u] += 1 << (v - 1);
		a[v] += 1 << (u - 1);
	}

	if (m == n * (n - 1) / 2) { std::cout << "0\n"; exit(0); }
	for (int i = 1; i <= n; i++) {
		f[a[i]] = 1;	// 介绍只需要一步
		q[a[i]] = i;	// i 号人的朋友互相认识只需要 i 来介绍
	}

	for (int s = 0; s < (1 << n); s++) {
		if (f[s] == inf) continue;
		for (int i = 1; i <= n; i++) {
			// 能被介绍并且步骤比之前更优
			if ((s & (1 << (i - 1))) && f[s | a[i]] > f[s] + 1) {
				f[s | a[i]] = f[s] + 1;	// 更新 DP 状态
				q[s | a[i]] = i;	// 达成 s | a[i] 状态是通过 i 介绍得到的
				fa[s | a[i]] = s;	// 原状态
			}
		}
	}

	std::cout << f[(1 << n) - 1] << "\n";
	find((1 << n) - 1);
	return 0;
}
