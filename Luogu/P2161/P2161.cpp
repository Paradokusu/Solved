// Problem: P2161 [SHOI2009] 会场预约
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2161
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

int n;

struct node {
	int l, r;
	bool operator < (const int &li) const {
		return r < li;
	}
};

std::vector<node> v;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		std::string str;
		std::cin >> str;
		if (str == "A") {
			int l, r;
			std::cin >> l >> r;
			auto it1 = std::lower_bound(v.begin(), v.end(), l);
			auto it2 = std::lower_bound(v.begin(), v.end(), r);
			if (it2 != v.end()) {
				if (it2->l <= r) it2++;
			}
			int cnt = it2 - it1;
			std::cout << cnt << "\n";
			v.erase(it1, it2);
			ans -= cnt;
			v.insert(it1, {l, r});
			ans++;
		} else std::cout << ans << "\n";
	}
	return 0;
}
