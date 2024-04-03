#include <bits/stdc++.h>

int k, x, y;
int sum;

int Get(int p) {
	int res = 1;
	
	for (int i = 1; i <= k; i++)
		res <<= 1;
	
	return res;
}

void Solve(int x, int y, int a, int b, int l) {
	if (l == 1) return;
	
	if (x - a <= l / 2 - 1 && y - b <= l / 2 - 1) {
		std::cout << a + l / 2 << " " << b + l / 2 << " 1\n";
		
		Solve(x, y, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	} else if (x - a <= l / 2 - 1 && y - b > l / 2 - 1) {
		std::cout << a + l / 2 << " " << b + l / 2 - 1 << " 2\n";

		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(x, y, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	} else if (x - a > l / 2 - 1 && y - b <= l / 2 - 1) {
		std::cout << a + l / 2 - 1 << " " << b + l / 2 << " 3\n";
		
		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(x, y, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	} else {
		std::cout << a + l / 2 - 1 << " " << b + l / 2 - 1 << " 4\n";
		
		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(x, y, a + l / 2, b + l / 2, l / 2);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> k;
	std::cin >> x >> y;
	
	sum = Get(k);
	Solve(x, y, 1, 1, sum);
	
	return 0;
}
