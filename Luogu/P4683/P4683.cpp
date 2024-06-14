#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;

int n, m, ans;
bool ed[N << 1], mk[N << 1];
char lf[N << 1];
std::string s, ot, l;

struct trie {
	int t0t, ch[N << 1][26];
	
	void insert(std::string x) {
		int u = 0;
		for (int i = 0; i < x.size(); i++) {
			int v = x[i] - 'a';
			if (!ch[u][v]) ch[u][v] = ++t0t;
			lf[ch[u][v]] = v + 'a';
			u = ch[u][v];
		}
		ed[u] = 1;
	}
	
	void mark(std::string x) {
		int u = 0;
		for (int i = 0; i < x.size(); i++) {
			int v = x[i] - 'a';
			mk[ch[u][v]] = 1;
			u = ch[u][v];
		}
	}
} tr;

void dfs(int x) {
	if (ed[x] == 1 && x != 0) {
		ans++;
		ot += "P";
	}
	
	if (ans == n) {
		std::cout << ot.size() << "\n";
		for (int i = 0; i < ot.size(); i++)
			std::cout << ot[i] << "\n";
		return;
	}
	
	int res;
	for (int i = 0; i < 26; i++) {
		res = tr.ch[x][i];
		if (mk[res] == 0 && res) {
			ot += lf[res];
			dfs(res);
			ot += "-";
		}
	}
	
	for (int i = 0; i < 26; i++) {
		res = tr.ch[x][i];
		if (mk[res] && res) {
			ot += lf[res];
			dfs(res);
			ot += "-";
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::string inp;
		std::cin >> inp;
		tr.insert(inp);
		if (l.size() < inp.size())
			l = inp;
	}
	
	tr.mark(l);
	dfs(0);
	
	return 0;
}
