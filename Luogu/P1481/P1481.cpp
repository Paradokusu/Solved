// Problem: P1481 魔族密码
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1481
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 2000 * 75 + 5;

int n, tot, ans;
std::array<int, N> word;
std::array<std::array<int, 26>, N> trie;

void Insert(std::string &str) {
	int u = 0, res = 0, len = str.size();
	for (int i = 0; i < len; i++) {
		int a = str[i] - 'a';
		if (trie[u][a] == 0) trie[u][a] = ++tot;
		u = trie[u][a];
		res += word[u];
	}
	word[u]++;
	if (res + 1 > ans) ans = res + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::string in;
		std::cin >> in;
		Insert(in);
	}
	std::cout << ans << "\n";
	return 0;
}
