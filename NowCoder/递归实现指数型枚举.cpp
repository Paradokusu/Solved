#include <bits/stdc++.h>

int n;
std::vector<int> chosen;

void calc(int x) {
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); i++)
            std::cout << chosen[i] << " ";
        std::cout << "\n";
        return;
    }

    calc(x + 1);

    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
    calc(1);
	return 0;
}
