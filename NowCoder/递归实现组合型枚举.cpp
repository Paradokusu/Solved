#include <bits/stdc++.h>

int n, m;
std::vector<int> chosen;

void calc(int x) {
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m)
        return;

    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); i++)
            std::cout << chosen[i] << " ";
        std::cout << "\n";
        return;
    }

    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();

    calc(x + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
    calc(1);
	return 0;
}
