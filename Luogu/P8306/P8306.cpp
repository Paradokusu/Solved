#include <bits/stdc++.h>

constexpr int N = 3e6 + 7;

int T, n, q, idx;
int word[N], trie[N][65];
char s[N];

void init(int n_) {
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < 122; j++)
			trie[i][j] = 0;
	}
	for (int i = 0; i <= idx; i++) {
		word[i] = 0;
	}
	idx = 0;
}

int Exchange(char x) {
	if (x >= 'A' && x <= 'Z')
		return x - 'A';
	else if (x >= 'a' && x <= 'z')
		return x - 'a' + 26;
	else
		return x - '0' + 52; 
}

void Insert(char *str) {
	int u = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int a = Exchange(str[i]);
		if (trie[u][a] == 0)
			trie[u][a] = ++idx;
		u = trie[u][a];
		word[u]++;
	}
}

int Find(char *str) {
	int u = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int a = Exchange(str[i]);
		if (trie[u][a] == 0)
			return 0;
		u = trie[u][a];
	}
	return word[u];
}

int main() {
	scanf("%d", &T);
	while (T--)  {
		scanf("%d %d", &n, &q);
		init(n);
		for (int i = 1; i <= n; i++) {
			scanf(" %s", s);
			Insert(s);
		}
		for (int i = 1; i <= q; i++) {
			scanf(" %s", s);
			printf("%d\n", Find(s));
		}
	}
	return 0;
}

