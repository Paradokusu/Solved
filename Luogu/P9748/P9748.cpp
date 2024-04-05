#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n;
	int ans = 0, day = 0;

	std::cin >> n;

	while (n) {
		ans++;

		if (n % 3 == 1 && day == 0)
			day = ans;

		if (n % 3 == 0)
			n -= n / 3;
		else
			n -= n / 3 + 1;
	}

	std::cout << ans << " " << day << "\n";
	return 0;
}
