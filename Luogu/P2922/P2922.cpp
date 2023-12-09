#include <bits/stdc++.h>

constexpr int N = 5e5 + 5;
using namespace std;

int n, m, cnt = 1;
std::array<int, N> b, strEnd, s;
std::array<std::array<int, 2>, N> trie;

void build() {
	int len;
	std::cin >> len;
	for (int i = 0; i < len; i++) std::cin >> s[i];
	int u = 1;
	for (int i = 0; i < len; i++) {
		int c = s[i];
		if (!trie[u][c]) trie[u][c] = ++cnt;
		u = trie[u][c];
	}
	b[u]++;
}

int make(int u) {
	int k1 = 0, k2 = 0;
	if (trie[u][0]) k1 = make(trie[u][0]);	// 搜索左边节点
	if (trie[u][1]) k2 = make(trie[u][1]);	// 搜索右边节点
	strEnd[u] = k1 + k2;	// u 后不包括点 u 有 k1 + k2 个节点
	return b[u] + strEnd[u];
}

void find() {
	int len;
	std::cin >> len;
	for (int i = 0; i < len; i++) std::cin >> s[i];
	int u = 1, sum = 0;
	for (int i = 0; i < len; i++) {
		int c = s[i];
		if (trie[u][c]) u = trie[u][c];
		else { std::cout << sum << "\n"; return; }
		sum += b[u];
	}
	std::cout << sum + strEnd[u] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) build();
	strEnd[1] = make(1);
	for (int i = 1; i <= m; i++) find();
	return 0;
}
