#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		std::string a, b;
		bool flag = false;
		std::cin >> a >> b;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i] && !flag) {
				for (int j = a.size(); j >= 0; j--) { 
					if (b[j] == a[j])
						for (int k = i; k <= j; k++)
							a[k] = b[k] = a[i];
					if (a == b) {
						std::cout << "YES" << std::endl;
						flag = true;
						break;
					}
				}
			}
			if (flag) break;
			
		}
		if (!flag)
			std::cout << "NO" << std::endl;

	}
	return 0;
}
