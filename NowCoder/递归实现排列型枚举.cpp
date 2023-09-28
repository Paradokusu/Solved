#include <bits/stdc++.h>

constexpr int N = 20;

int n;
std::vector<int> order(N + 5);
std::vector<bool> chosen(N + 5);

void calc(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++)
            std::cout << order[i] << " ";
        std::cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (chosen[i]) continue;
        order[k] = i;
        chosen[i] = true;
        calc(k + 1);
        chosen[i] = 0;
    }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n;
	calc(1);
	return 0;
}
