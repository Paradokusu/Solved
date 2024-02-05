#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 7;

int n, cnt, root;
int f[N], g[N], ch[N][5]; 
char str[N];

void Build(int &rt) {
	rt = ++cnt;
	int opt = str[cnt] - '0';
	
	if (opt == 0)
		return;
	if (opt == 1)
		Build(ch[rt][1]);
	if (opt == 2) {
		Build(ch[rt][1]);
		Build(ch[rt][2]);
	}
}

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	
	Build(root);
	for (int i = n; i >= 1; i--) {
		f[i] = g[ch[i][1]] + g[ch[i][2]] + 1;
		g[i] = max(f[ch[i][1]] + g[ch[i][2]], f[ch[i][2]] + g[ch[i][1]]);
	}
	
	printf("%d ", max(f[1], g[1]));
	for (int i = n; i >= 1; i--) {
		f[i] = g[ch[i][1]] + g[ch[i][2]] + 1;
		g[i] = min(f[ch[i][1]] + g[ch[i][2]], f[ch[i][2]] + g[ch[i][1]]);
	}
	
	printf("%d\n", min(f[1], g[1]));
	return 0;
}
