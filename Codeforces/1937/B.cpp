#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string a[3];

	std::cin >> a[1];
	std::cin >> a[2];
	a[1] = '#' + a[1];
	a[2] = '#' + a[2];
	
	int mxdown = n, mndown = 1;
	
	for (int i = n; i >= 2; i--) {
		if (a[1][i] == '1' && a[2][i - 1] == '0')
			mxdown = i - 1;
	}
	
	for (int i = 1; i < mxdown; i++) {
		if (a[2][i] == '1' && a[1][i + 1] == '0')
			mndown = i + 1;
	}
	
	for (int i = 1; i <= mxdown; i++)
		std::cout << a[1][i];
	
	for (int i = mxdown; i <= n; i++)
		std::cout << a[2][i];
	
	std::cout << "\n" << mxdown - mndown + 1 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int t;
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
