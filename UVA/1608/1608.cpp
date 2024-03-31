#include <bits/stdc++.h>

constexpr int N = 2e5 + 7;

int t, n;
int s[N], lst[N], nxt[N];

std::map<int, int> be, wi;

bool solve(int l, int r) {
	if (l >= r)
		return 1;

	int x = l, y = r;

	while (x <= r) {
		if (lst[x] < l && nxt[x] > r)
			return solve(l, x - 1) && solve(x + 1, r);
		else if (lst[y] < l && nxt[y] > r)
			return solve(l, y - 1) && solve(y + 1, r);

		x++, y--;
	}

	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> t;

	while (t--) {
		std::cin >> n;
		be.clear();
		wi.clear();

		for (int i = 1; i <= n; i++) {
			std::cin >> s[i];

			if (!be.count(s[i]))
				lst[i] = -1;
			else
				lst[i] = be[s[i]];

			be[s[i]] = i;
		}

		for (int i = n; i; i--) {
			if (!wi.count(s[i]))
				nxt[i] = n + 1;
			else
				nxt[i] = wi[s[i]];

			wi[s[i]] = i;
		}

		if (solve(1, n))
			std::cout << "non-boring\n";
		else
			std::cout << "boring\n";
	}

	return 0;
}
