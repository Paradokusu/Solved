#include <bits/stdc++.h>

constexpr int N = 2e2 + 7;

int n;
int ord[N], ind[N];
char ans[N], word[N][N];

std::vector<int> td, e[N];

void addedge(int x, int y) {
	int xsize = strlen(word[x] + 1);
	int ysize = strlen(word[y] + 1);
	
	for (int i = 1; i <= std::min(xsize, ysize); i++) {
		if (word[x][i] != word[y][i]) {
			e[word[x][i]].push_back(word[y][i]);
			if (ind[word[x][i]] == -1)
				ind[word[x][i]] = 0;
			if (ind[word[y][i]] == -1)
				ind[word[y][i]] = 1;
			else
				ind[word[y][i]]++;
			return;
		}
	}
	
	if(xsize > ysize) {
		printf("NE\n");
		exit(0);
	}
}

void topo() {
	std::queue<int> q;
	for (int i = 'a'; i <= 'z'; i++)
		if (!ind[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		td.push_back(u);
		for (auto v : e[u]) {
			ind[v]--;
			if (ind[v] == 0)
				q.push(v);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 'a'; i <= 'z'; i++)
		ind[i] = -1;
	for (int i = 1; i <= n; i++)
		scanf(" %s", word[i] + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ord[i]);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++)
			addedge(ord[i], ord[j]);
	}
	topo();
	for (int i = 'a'; i <= 'z'; i++)
		if (ind[i] > 0) {
			printf("NE\n");
			exit(0);
		}
	
	printf("DA\n");
	int cot = 0;
	for (auto i : td)
		ans[i] = 'a' + cot++;
	for (int i = 'a'; i <= 'z'; i++)
		if (!ans[i])
			printf("%c", (char) 'a' + cot++);
		else
			printf("%c", (char) ans[i]);
	printf("\n");
	return 0;
}
