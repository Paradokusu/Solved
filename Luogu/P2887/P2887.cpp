#include <bits/stdc++.h>

constexpr int N = 2500 + 7;

int n, m;

struct COW {
	int l, r;
} cow[N];

struct SPF {
	int s, c;
} spf[N];

bool cmp1(const COW &a, const COW &b) {
	return a.l > b.l;
}

bool cmp2(const SPF &a, const SPF &b) {
	return a.s > b.s;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
		std::cin >> cow[i].l >> cow[i].r;

	for (int i = 1; i <= m; i++)
		std::cin >> spf[i].s >> spf[i].c;
	
	std::sort(cow + 1, cow + n + 1, cmp1);
	std::sort(spf + 1, spf + m + 1, cmp2);
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (spf[j].c && (spf[j].s >= cow[i].l && spf[j].s <= cow[i].r)) {
				ans++;
				spf[j].c--;
				break;
			}
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}
