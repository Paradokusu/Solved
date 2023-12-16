#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> all(n + 5), nd(n + 5), col(n + 5);
	for (int i = 1; i <= n; i++) {
		std::cin >> col[i];
		all[col[i]]++, nd[col[i]] = i;
	}

	int tot = 0;
	std::vector<int> fi(n + 5), nxt(n * 2 + 5), to(n * 2 + 5);
	std::function<void(int, int)> add = [&](int u, int v) {
		to[++tot] = v;
		nxt[tot] = fi[u];
		fi[u] = tot;
	};
	
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		add(u, v);
		add(v, u);
	}

	std::vector<int> si(n + 5), nds(n + 5), cnt(n + 5);
	std::vector<i64> res(n + 5), f(n + 5);
	std::function<void(int, int)> dfs = [&](int x, int la) {
		int c = col[x], ct = cnt[c], flg = 0, pos = 0;
		si[x] = 1;
		for (int i = fi[x]; i; i = nxt[i]) {
			int u = to[i];
			if (u == la) continue;
			int las = cnt[c];
			dfs(u, x);
			f[x] += 1ll * si[u] * si[x];
			si[x] += si[u];
			if (las != cnt[c]) ++flg, pos = u;
		}
		f[x] += 1ll * si[x] * (n - si[x]);
		if (ct || cnt[c] != all[c] - 1) ++flg, ++cnt[c];
		
		if (flg == 1) {
			if (!nds[c]) nd[c] = x;
			else res[c] = 1ll * si[nd[c]] * (pos ? n - si[pos] : si[x]);
			++nds[c];
		}
	};
	dfs(1, 1);

	for (int i = 1; i <= n; i++) {
		if (all[i] == 0) std::cout << (1ll * n * (n - 1) / 2);
		else if (all[i] == 1) std::cout << f[nd[i]];
		else if (nds[i] == 2) std::cout << res[i];
		else std::cout << "0";
		std::cout << "\n";
	}
	return 0;
}
