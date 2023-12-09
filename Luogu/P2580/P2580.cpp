// Problem: P2580 于是他错误的点名开始了
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2580
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

constexpr int N = 1e4 * 50 + 5;

int n, m, tot;
std::array<std::array<int, 26>, N> trie;
std::array<int, N> word, cnt;

void Insert(std::string &str) {
	int u = 0, len = str.size();
	for (int i = 0; i < len; i++) {
		int a = str[i] - 'a';
		if (trie[u][a] == 0) trie[u][a] = ++tot;
		u = trie[u][a];
	}
	word[u]++;
}

int Find(std::string &str) {
	int u = 0, len = str.size();
	for (int i = 0; i < len; i++) {
		int a = str[i] - 'a';
		if (trie[u][a] == 0) return -1;
		u = trie[u][a];
	}
	return word[u] ? cnt[u]++ : -1;
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
	std::cin >> m;
	while (m--) {
		int res;
		std::string str;
		std::cin >> str;
		res = Find(str);
		if (res == -1) std::cout << "WRONG\n";
		else if (res == 0) std::cout << "OK\n";
		else std::cout << "REPEAT\n";
	}
	return 0;
}
