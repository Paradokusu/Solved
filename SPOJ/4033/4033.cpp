#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 5;

int tot, num[N], trie[N][55];
char str[N][55];

void insert(char str[]) {
	int u = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int x = str[i] - '0';
		if (!trie[u][x]) trie[u][x] = ++tot;
		u = trie[u][x], num[u]++;
	}
}

int find(char str[]) {
	int u = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int x = str[i] - '0';
		if (!trie[u][x]) return 0;
		u = trie[u][x];
	}
	return num[u];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, flag = 0;
		tot = 0;
		memset(trie, 0, sizeof(trie));
		memset(num, 0, sizeof(num));

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str[i]);
			insert(str[i]);
		}
		for (int i = 1; i <= n; i++) {
			int x = find(str[i]);
			if (x > 1) flag = 1;	// 是前缀
		}
		if (!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
